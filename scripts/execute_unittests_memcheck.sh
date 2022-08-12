#!/bin/bash

set -e

cd ../build_unittest/output
valgrind --tool=memcheck ./unittests --gtest_filter=-*Death*
