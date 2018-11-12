#!/bin/bash

a=$1
b=$2
r=1
while [[ $b -ne 0 ]]; do
r=$(($a%$b))
a=$(($b))
b=$(($r))
done

echo $a
echo $((($1*$2)/$a))
