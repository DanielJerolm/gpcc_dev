#!/bin/bash

set -e

cd ..

rm -fr build_linuxnative

cmake -S . -B build_linuxnative -DGPCCDEV_Artifact:STRING=productive_native_linux -DCMAKE_BUILD_TYPE=custom_release

echo "Done"