#!/bin/bash

# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file,
# You can obtain one at https://mozilla.org/MPL/2.0/.
#
# Copyright (C) 2022 Daniel Jerolm

set -e

cd ..

rm -fr build_linuxnative

cmake -S . \
      -B build_linuxnative \
      -DGPCCDEV_Artifact:STRING=productive_linux_native \
      -DCMAKE_BUILD_TYPE=custom_release

echo "Done"
