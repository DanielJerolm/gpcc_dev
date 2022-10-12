#!/bin/bash

# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file,
# You can obtain one at https://mozilla.org/MPL/2.0/.
#
# Copyright (C) 2022 Daniel Jerolm

set -e

cd ..

rm -fr build_chibiosrt
rm -fr build_linuxnative
rm -fr build_unittest

echo "Done"
