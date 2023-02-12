#!/bin/bash
app=../rps
prefix=data
inPostFix='.in'
outPostFix='.ans'
from=5
to=38
for ((i = $from; i <= $to; ++i))
do
  in=$prefix$i$inPostFix
  echo $in
  op1=$($app < $in)
  echo $op1
  echo ''
  op1="${op1//[$'\t\r\n ']}"

  out=$prefix$i$outPostFix
  echo $out
  op2=$(cat $out)
  echo $op2
  echo ''
  op2="${op2//[$'\t\r\n ']}"

  if [ "$op1" -eq "$op2" ]
  then
    echo 'pass'
  else
    echo 'fail'
    break
  fi
done
