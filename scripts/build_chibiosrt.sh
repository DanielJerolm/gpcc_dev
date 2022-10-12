#!/bin/bash

# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file,
# You can obtain one at https://mozilla.org/MPL/2.0/.
#
# Copyright (C) 2022 Daniel Jerolm

set -e

# ensure that exactly one argument has been passed to the script
if [ $# -eq 0 ]; then
  echo "One argument expected: 'clean' or 'all' or 'rebuild'"
  exit 1
fi

# ensure that the build-directoy exists
if [ ! -d "../build_chibiosrt" ]; then
  echo "Build-directory does not exist."
  echo "Did you run 'cmake_init_chibiosrt_release.sh'?"
  exit 1
fi

./build_x.sh build_chibiosrt $1
