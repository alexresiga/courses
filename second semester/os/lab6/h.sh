#!/bin/bash
while [ "$1" ]; do
	count=`cat $1 | grep -o "\b$2\b" | wc -l`
	if [ $count -gt 2 ]; then
		echo $1
	fi
shift 2
done
