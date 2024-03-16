#!/bin/bash
if [[ "$1" == "c" || "$1" == "cc" ]]; then
  cp ../template.$1 ./main.$1
else
  echo "usage: $0 {c | cc}"
fi
