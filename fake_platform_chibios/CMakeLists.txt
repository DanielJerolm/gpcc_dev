# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file,
# You can obtain one at https://mozilla.org/MPL/2.0/.
#
# Copyright (C) 2022 Daniel Jerolm


# Main CMakeLists.txt-file for fake_platform_chibios
# ==================================================
#
# Intended use
# ------------
# This will create a library "fake_platform_chibios" providing everything required by GPCC to be compiled without
# presence of a real ChibiOS/RT implementation.
#
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(fake_platform_chibios LANGUAGES C)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
               PRIVATE
               ${CMAKE_CURRENT_LIST_DIR}/src_notest/chibios/fake.c
               ${CMAKE_CURRENT_LIST_DIR}/src_notest/user_extensions/fake.c
              )

target_include_directories(${PROJECT_NAME}
                           PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/include
                          )
