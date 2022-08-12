# Sub-CMakeLists-file for gpcc_dev, builds unit test executable for the host using the native toolchain
# =====================================================================================================
#
# Host system requirements
# ------------------------
# - Linux
# - CPU: x86_64, amd64, arm, or arm64
# - GNU/GCC toolchain
#
# Configuration
# -------------
#
# The unit test executable will include all of GPCC's unit tests, even those that depend on CPU load. To achieve
# reproducable results (e.g. on a build-server) you have to exclude these tests. To do so, specify the following when
# configuring the project:
# -DGPCC_SkipLoadDependentTests:BOOL=ON
#
# If required, you may also specify:
# -DGPCC_SkipVeryBigMemTests:BOOL=ON
# -DGPCC_SkipSpecialRightsBasedTests:BOOL=ON
#
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(gpcc_unittest_executable LANGUAGES CXX)

include(toolchain_configs/native_gcc/settings.x86_64-any-linux.cmake)

# ---------------------------------------------------------------------------------------------------------------------
# Configure GPCC
# ---------------------------------------------------------------------------------------------------------------------
set(GPCC_TargetEnvironment "unittest" CACHE STRING "" FORCE)

if((CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "amd64"))
  set(GPCC_Compiler "gcc_x64" CACHE STRING "" FORCE)
  set(GPCC_OS "linux_x64_tfc" CACHE STRING "")
elseif((CMAKE_SYSTEM_PROCESSOR STREQUAL "arm" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "arm64"))
  set(GPCC_Compiler "gcc_arm" CACHE STRING "" FORCE)
  set(GPCC_OS "linux_arm_tfc" CACHE STRING "")
else()
  message(FATAL_ERROR "System processor (${CMAKE_SYSTEM_PROCESSOR}) not supported. Supported processors:\n"
                      "x86_64, amd64, arm, arm64")
endif()

set(GPCC_SkipTFCBasedTests OFF CACHE BOOL "")
set(GPCC_SkipLoadDependentTests OFF CACHE BOOL "")
set(GPCC_SkipVeryBigMemTests OFF CACHE BOOL "")
set(GPCC_SkipSpecialRightsBasedTests OFF CACHE BOOL "")

# ---------------------------------------------------------------------------------------------------------------------
# Add required sub-projects
# ---------------------------------------------------------------------------------------------------------------------
set(INSTALL_GTEST OFF CACHE BOOL "Prevent installation of googletest" FORCE)
add_subdirectory(googletest)
add_subdirectory(gpcc)

# ---------------------------------------------------------------------------------------------------------------------
# Desired artifact: Unit test executable
# ---------------------------------------------------------------------------------------------------------------------
add_executable(${PROJECT_NAME} empty.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE gpcc gpcc_testcases gmock_main)

set_target_properties(${PROJECT_NAME} PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/output"
                      OUTPUT_NAME "unittests"
                     )
