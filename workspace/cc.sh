#!/bin/bash
# clang-format -style=file:cpp -i main.cc
# wget https://apt.llvm.org/llvm.sh
# chmod u+x llvm.sh
# sudo ./llvm.sh 17
# sudo apt install clang-format-17 -y
clang-format-17 -style='file:cc.clang-format' -i main.cc
cpplint main.cc
clang++ main.cc -O2 -Wall -lm -static -std=c++14
if [ -z "$1" ]; then
  ./a.out
else
  ./a.out < $1
fi
