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
               ${CMAKE_CURRENT_LIST_DIR}/src_notest/system_time/fake.c
              )

target_include_directories(${PROJECT_NAME}
                           PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/include
                          )
