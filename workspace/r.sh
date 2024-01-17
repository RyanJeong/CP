#!/bin/bash
if [ -z "$1" ]; then
  echo "USAGE: ./r.sh {TARGET_CPP} [INPUT]"
  exit 1
fi

cpplint $1
g++ $1 -std=c++14 -Wall -Werror
if [ -z "$2" ]; then
  ./a.out
else
  ./a.out < $2
fi
