# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file,
# You can obtain one at https://mozilla.org/MPL/2.0/.
#
# Copyright (C) 2022 Daniel Jerolm


# Sub-CMakeLists-file for gpcc_dev, builds the productive library for the native Linux host
# =========================================================================================
#
# Host system requirements
# ------------------------
# - Linux
# - CPU: x86_64, amd64, arm, or arm64
# - GNU/GCC toolchain
#


# Note: Current working directory is gpcc_dev's root directory

cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(gpcc_productive_linux LANGUAGES CXX)

include(extern/toolchain_configs/native_gcc/settings.x86_64-any-linux.cmake)

# ---------------------------------------------------------------------------------------------------------------------
# Configure GPCC
# ---------------------------------------------------------------------------------------------------------------------
set(GPCC_TargetEnvironment "productive" CACHE STRING "" FORCE)

if((CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "amd64"))
  set(GPCC_Compiler "gcc_x64" CACHE STRING "" FORCE)
  set(GPCC_OS "linux_x64" CACHE STRING "" FORCE)
elseif((CMAKE_SYSTEM_PROCESSOR STREQUAL "arm" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "arm64"))
  set(GPCC_Compiler "gcc_arm" CACHE STRING "" FORCE)
  set(GPCC_OS "linux_arm" CACHE STRING "" FORCE)
else()
  message(FATAL_ERROR "System processor (${CMAKE_SYSTEM_PROCESSOR}) not supported. Supported processors:\n"
                      "x86_64, amd64, arm, arm64")
endif()

# ---------------------------------------------------------------------------------------------------------------------
# Add required sub-projects
# ---------------------------------------------------------------------------------------------------------------------
add_subdirectory(extern/gpcc)
