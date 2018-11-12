#!/bin/bash
sum=0
for x in $@; do
	if [[ $x =~ [aeiou][aeiou]* ]]; then
	sum=$(($sum +1))
	fi
done
echo $sum
