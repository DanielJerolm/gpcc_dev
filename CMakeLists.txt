# Main CMakeLists.txt-file for gpcc_dev
# =====================================
#
# System requirements
# -------------------
# - Linux host system
# - CPU: x86_64, amd64, arm, or arm64
# - GNU/GCC toolchain as required by artifact (see "configuration" below)
#
# Intended use
# ------------
#
# gpcc_dev is intended to be used for development of GPCC. gpcc_dev allows to build GPCC in different configurations
# for different platforms, inclusive unit tests for the host. It offers any additional sources required to build GPCC:
# - googletest
# - fakes for supported RTOS environments
# - toolchain description files for cross-builds
#
# Configuration
# -------------
#
# You have to select the artifact that shall be build and set the cache variable "GPCCDEV_Artifact" accordingly:
# - productive_chibios_arm:
#     A library "gpcc" will be build for productive use and it will be linked against "fake_platform_chibios". This will
#     be a cross-build. When configuring the project, you have to provide a toolchain file specifying the toolchain and
#     CPU architecture specific settings. Usually one will use one of the files from "toolchain_configs".
#     Example:
#     cmake -S . -B build_chibiosrt
#           -DCMAKE_TOOLCHAIN_FILE=toolchain_configs/cross_gcc/settings.arm-none-eabi-posix.cortex-m3.cmake
#           -DGPCCDEV_Artifact:STRING=productive_chibios_arm
#           -DCMAKE_BUILD_TYPE=custom_release
#
# - productive_native_linux:
#     A library "gpcc" will be build for productive use on the local host (x86_64, amd64, arm, or arm64) using the
#     native gcc compiler. No toolchain file must be provided when configuring the project.
#     Example:
#     cmake -S . -B build_linuxnative -DGPCCDEV_Artifact:STRING=productive_native_linux -DCMAKE_BUILD_TYPE=custom_release
#
# - unittest:
#     An executable containing GPCC's unit tests will be build for use on the local host (x86_64, amd64, arm, or arm64)
#     using the native gcc compiler. No toolchain file must be provided when configuring the project.
#     Example:
#     cmake -S . -B build_unittest -DGPCCDEV_Artifact:STRING=unittest -DCMAKE_BUILD_TYPE=custom_release
#
# After configuration it is strongly recommended that you check your settings:
# 1. cd to you build directory
# 2. Type: cmake . -LA | grep GPCC_
#    To include help text, type: cmake . -LAH | grep -B 1 GPCC_
#
# In addition to "GPCCDEV_Artifact", grep will show some more options depending on the selected artifact. There are
# reasonable defaults for these settings, but you should have a look at them and confirm them.
#
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(gpcc_dev)

# ---------------------------------------------------------------------------------------------------------------------
# User setting "GPCCDEV_Artifact"
# ---------------------------------------------------------------------------------------------------------------------
set(GPCCDEV_Artifact CACHE STRING "Selects the artifact that shall be build.")
set(GPCCDEV_ArtifactValues "productive_chibios_arm;productive_native_linux;unittest")

string(REPLACE ";"  ", " GPCCDEV_ArtifactValues_str "${GPCCDEV_ArtifactValues}")
set_property(CACHE GPCCDEV_Artifact PROPERTY STRINGS ${GPCCDEV_ArtifactValues})

if(NOT GPCCDEV_Artifact)
  message(FATAL_ERROR "Error: 'GPCCDEV_Artifact' is not set.\n"
                      "Allowed values: ${GPCCDEV_ArtifactValues_str}")
endif()
if(NOT (${GPCCDEV_Artifact} IN_LIST GPCCDEV_ArtifactValues))
  message(FATAL_ERROR "Error: 'GPCCDEV_Artifact' has invalid value.\n"
                      "Allowed values: ${GPCCDEV_ArtifactValues_str}")
endif()

# ---------------------------------------------------------------------------------------------------------------------
# Continue in cmake files specific to the artifact
# ---------------------------------------------------------------------------------------------------------------------
if(${GPCCDEV_Artifact} STREQUAL "productive_chibios_arm")
  include(CMakeLists.chibios_arm.cmake)
elseif(${GPCCDEV_Artifact} STREQUAL "productive_native_linux")
  include(CMakeLists.linux_native.cmake)
elseif(${GPCCDEV_Artifact} STREQUAL "unittest")
  include(CMakeLists.unittest.cmake)
else()
  message(FATAL_ERROR "Error: Value of 'GPCCDEV_Artifact' not supported.")
endif()
