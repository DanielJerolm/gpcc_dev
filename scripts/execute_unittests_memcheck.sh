#!/bin/bash

# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file,
# You can obtain one at https://mozilla.org/MPL/2.0/.
#
# Copyright (C) 2022 Daniel Jerolm

set -e

cd ../build_unittest/output
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./unittests --gtest_filter=-*Death*:-*DeferredCancel*
