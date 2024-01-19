#!/bin/bash
cpplint main.cc
# clang-format -style=Google -i main.cc
clang++ main.cc -O2 -Wall -lm -static -std=c++14
if [ -z "$1" ]; then
  ./a.out
else
  ./a.out < $1
fi
