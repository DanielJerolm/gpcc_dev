#!/bin/bash

# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file,
# You can obtain one at https://mozilla.org/MPL/2.0/.
#
# Copyright (C) 2021 Daniel Jerolm


# This script performs one of the following build operations on a build_...-folder in the parent directory:
# Clean, incremental build or rebuild (= clean + build).
#
# Invocation: ./build_x.sh <build_...-folder> (clean | all | rebuild)

set -e

script_path=$(cd $(dirname $0) && pwd -P)
. $script_path/colorcodes.sh

print_done() {
  echo -e "${BGreen}Done. Configured build type:"
  grep 'CMAKE_BUILD_TYPE' CMakeCache.txt
  echo -e "${Color_Off}"
}


# check number of arguments
if [ $# -ne 2 ]; then
  echo "Exactly two arguments expected: <build_...-folder> (clean | all | rebuild)"
  exit 1
fi

echo -e "${Cyan}========================================================================="
echo           "CMake-project: $1"
echo -e        "=========================================================================${Color_Off}"

# ensure that the build_...-folder is existing
if [ ! -d "../$1" ]; then
  echo "Specified build_...-folder is not existing. Did you execute 'cmake_init_xxx.sh'?"
  exit 1
fi

# enter build folder
cd ../$1

CORES=$(nproc)

if [ "$2" == "clean" ]; then
  echo "Clean..."
  make clean
  print_done
elif [ "$2" == "all" ]; then
  echo "Incremental build..."
  cmake --build . --parallel ${CORES}
  print_done
elif [ "$2" == "rebuild" ]; then
  echo "Clean rebuild..."
  make clean
  cmake --build . --parallel ${CORES}
  print_done
else
  echo "Invalid argument! Valid arguments are: 'clean', 'all' and 'rebuild'."
  exit 1
fi
