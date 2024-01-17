#!/bin/bash
cpplint main.cc
clang++ main.cc -std=c++14 -Wall -Wextra
if [ -z "$1" ]; then
  ./a.out
else
  ./a.out < $1
fi
