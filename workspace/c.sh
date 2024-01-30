#!/bin/bash
# clang-format -style='file:c.clang-format' -i main.c
clang-format-17 -style='file:c.clang-format' -i main.c
cpplint --filter="-legal/copyright,-whitespace/braces,-runtime/int,-readability/casting,-build/include_subdir,-build/header_guard" main.c
gcc main.c -O2 -Wall -lm -static -ansi
if [ -z "$1" ]; then
  ./a.out
else
  ./a.out < $1
fi
