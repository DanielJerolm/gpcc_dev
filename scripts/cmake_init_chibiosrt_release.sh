#!/bin/bash

set -e

cd ..

rm -fr build_chibiosrt

cmake -S . -B build_chibiosrt -DCMAKE_TOOLCHAIN_FILE=toolchain_configs/cross_gcc/toolchain.arm-none-eabi-posix.cortex-m3.cmake -DGPCCDEV_Artifact:STRING=productive_chibios_arm -DCMAKE_BUILD_TYPE=custom_release

echo "Done"
