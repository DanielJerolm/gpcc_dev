#!/bin/bash

set -e

cd ..

rm -fr build_unittest

cmake -S . \
      -B build_unittest \
      -DGPCCDEV_Artifact:STRING=unittest \
      -DCMAKE_BUILD_TYPE=custom_release

echo "Done"
