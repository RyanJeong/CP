#!/bin/bash
cpplint main.c
# clang-format -style=Google -i main.cc
gcc main.c -O2 -Wall -lm -static -ansi
if [ -z "$1" ]; then
  ./a.out
else
  ./a.out < $1
fi
