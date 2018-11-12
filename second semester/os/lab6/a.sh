#!/bin/bash

#sa se citeasca nume de fisiere de la tastura pana cand numarul lor de linii depaseste 10

cnt=0
while [ $cnt -le 10 ]; do
	read x
	if [ -f $x ]; then
	file=$(cat $x| wc -l)
	cnt=$(($cnt+$file))
	fi
done
echo $cnt
