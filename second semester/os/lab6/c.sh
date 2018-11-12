#!/bin/bash

s=0
prefix=$1
shift
while [ $# -ne 0 ]; do
	# aux=$((echo $1 | grep -E "^$prefix" | wc -l ))
	echo $1 | grep "^$prefix" > a.txt  && s=$(($s +1))
shift
done
echo $s
