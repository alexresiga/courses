#!/bin/bash

sum=0
for x in $@
do
sum=$(($sum + $x))
done

echo $sum
