#!/bin/bash

# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file,
# You can obtain one at https://mozilla.org/MPL/2.0/.
#
# Copyright (C) 2022, 2024 Daniel Jerolm

set -e

cd ../build_unittest/output
if [ $# -eq 0 ]; then
  valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./unittests --gtest_filter=-*Death*:-*DeferredCancel*
else
  valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./unittests $@
fi
