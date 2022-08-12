#!/bin/bash

set -e

cd ../build_unittest/output
./unittests $@
