#!/bin/bash
count=0
lines=0
for x in `find $1`; do
	if [ -f $x ]; then
	count=$(($count+1))
	l=`cat $x | wc -l`
	lines=$(($lines + $l))
	fi
done
echo $(( $lines/$count))
