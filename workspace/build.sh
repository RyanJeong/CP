#!/bin/bash
# TODO: need to apply more improved clang-format and cpplint
# clang-format -style=file:cpp -i main.cc

run_command() {
  local command="$1"
  local eval_result=

  echo -e "\t\t$command"
  eval "$command" >/dev/null

  if [ $? -eq 0 ]; then
    eval_result="> Done."
  else
    eval_result="> Failed. (exit code: $?)"
  fi
  echo -e "\t\t$eval_result"
}

if [[ "$1" == "c" || "$1" == "cc" ]]; then
  CP_CPPLINT=cpplint
  CP_CPPLINT_ARGS=
  CP_CLANG_FORMAT=clang-format-17
  CP_CLANG_FORMAT_ARGS="-style=file:$1.clang-format"
  CP_TARGET=main.$1
  CP_COMPILER=
  CP_COMPILER_FLAGS=
  CP_COMPILER_OUTPUT="$1"
  CP_COMPILER_OUTPUT_DEBUG="$1debug"
  CP_COMPILER_OUTPUTS="$CP_COMPILER_OUTPUT $CP_COMPILER_OUTPUT_DEBUG"
  CP_BOJ_MACRO="-DONLINE_JUDGE -DBOJ"
  CP_MACRO_DEBUG="-DCP_MSJEONG_DEBUG"

  if [[ "$1" == "c" ]]; then
    # CP_CPPLINT_ARGS="--filter=\"-legal/copyright,-whitespace/braces,-runtime/int,-readability/casting,-build/include_subdir,-build/header_guard\""
    CP_CPPLINT_ARGS="--filter=\"-whitespace/braces,-runtime/int,-readability/casting,-build/include_subdir,-build/header_guard\""
    CP_COMPILER="gcc"
    CP_COMPILER_FLAGS="-O2 -Wall -lm -static -ansi"
  elif [[ "$1" == "cc" ]]; then
    CP_COMPILER="clang++"
    CP_COMPILER_FLAGS="-O2 -Wall -lm -static -std=c++14"
  fi

  echo "Removing previous outputs ..."
  rm $CP_COMPILER_OUTPUTS 2>/dev/null
  echo

  if ! which $CP_CLANG_FORMAT >/dev/null; then
    echo "There is no ${CP_CLANG_FORMAT}. You can install it by following commands:"
    echo "wget https://apt.llvm.org/llvm.sh"
    echo "chmod u+x llvm.sh"
    echo "sudo ./llvm.sh 17"
    echo "sudo apt install clang-format-17 -y"
  else
    echo "Formatting using $CP_CLANG_FORMAT ..."
    run_command "$CP_CLANG_FORMAT $CP_CLANG_FORMAT_ARGS -i $CP_TARGET"
  fi

  if ! which $CP_CPPLINT >/dev/null; then
    echo "There is no ${CP_CPPLINT}. You can install it by following commands:"
    echo "sudo apt update && sudo apt install python3-pip -y"
    echo "pip3 install --user cpplint"
    echo "sudo ln -s /home/USER_NAME/.local/bin/cpplint /usr/bin"
  else
    echo "Linting using $CP_CPPLINT ..."
    run_command "$CP_CPPLINT $CP_CPPLINT_ARGS $CP_TARGET"
  fi


  echo "Building $CP_TARGET using $CP_COMPILER ..."
  run_command "$CP_COMPILER -o $CP_COMPILER_OUTPUT_DEBUG $CP_TARGET \
    $CP_COMPILER_FLAGS $CP_BOJ_MACRO \
    $CP_MACRO_DEBUG"
  run_command "$CP_COMPILER -o $CP_COMPILER_OUTPUT $CP_TARGET \
    $CP_COMPILER_FLAGS $CP_BOJ_MACRO"

  ls $CP_COMPILER_OUTPUTS 2>/dev/null
else
  echo "usage: $0 {c | cc}"
fi
