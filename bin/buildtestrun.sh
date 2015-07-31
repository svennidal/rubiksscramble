#!/bin/bash
clang++ -std=c++11 -Wall -pedantic -ggdb -o runTest test/test.cpp Moves.cpp
./runTest
