#!/bin/bash

# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file,
# You can obtain one at https://mozilla.org/MPL/2.0/.
#
# Copyright (C) 2022 Daniel Jerolm

set -e

cd ..

rm -fr build_chibiosrt

cmake -S . \
      -B build_chibiosrt \
      -DTOOLCHAIN_VERSION=10.3 \
      -DCMAKE_TOOLCHAIN_FILE=toolchain_configs/cross_gcc/toolchain.arm-none-eabi-posix.cortex-m3.cmake \
      -DGPCCDEV_Artifact:STRING=productive_chibios_arm \
      -DCMAKE_BUILD_TYPE=custom_release

echo "Done"
