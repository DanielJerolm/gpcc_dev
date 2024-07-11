# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file,
# You can obtain one at https://mozilla.org/MPL/2.0/.
#
# Copyright (C) 2022 Daniel Jerolm


# Sub-CMakeLists-file for gpcc_dev, builds the productive library for Chibios/RT environment
# ==========================================================================================


# Note: Current working directory is gpcc_dev's root directory

cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(gpcc_productive_chibios LANGUAGES CXX)

Validate_CMAKE_BUILD_TYPE_is_custom()

if(NOT CMAKE_CROSSCOMPILING)
  message(FATAL_ERROR "Attempt to cross compile NOT detected.\n"
                      "This project is intended to be build on a linux host for an ARM target and ChibiOS/RT.")
endif()

# ---------------------------------------------------------------------------------------------------------------------
# Configure GPCC
# ---------------------------------------------------------------------------------------------------------------------
set(GPCC_TargetEnvironment "productive" CACHE STRING "" FORCE)
set(GPCC_Compiler "gcc_arm" CACHE STRING "" FORCE)
set(GPCC_OS "chibios_arm" CACHE STRING "" FORCE)

# ---------------------------------------------------------------------------------------------------------------------
# Add required sub-projects
# ---------------------------------------------------------------------------------------------------------------------
add_subdirectory(fake_platform_chibios)
add_subdirectory(extern/gpcc)
target_link_libraries(gpcc PRIVATE fake_platform_chibios)
