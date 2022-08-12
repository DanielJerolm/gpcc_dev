#!/bin/bash

set -e

# ensure that exactly one argument has been passed to the script
if [ $# -eq 0 ]; then
  echo "One argument expected: 'clean' or 'all' or 'rebuild'"
  exit 1
fi

# ensure that the build-directoy exists
if [ ! -d "../build_unittest" ]; then
  echo "Build-directory does not exist."
  echo "Did you run 'cmake_init_unittest_debug.sh' or 'cmake_init_unittest_release.sh'?"
  exit 1
fi

./build_x.sh build_unittest $1
