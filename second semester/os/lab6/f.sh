#!/bin/sh

x=0
sum=0
while [ $x !=  "stop" ]
do
sum=$((sum+ $x))
read x
done
echo $sum
