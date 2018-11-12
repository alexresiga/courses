#!/bin/bash

prefix=$1
shift
cnt=0
while [ $# -ne 0 ]; do
	if [[ $1 =~ ^$prefix ]]; then
		cnt=$(($cnt+1))
	fi
shift
done
echo $cnt
