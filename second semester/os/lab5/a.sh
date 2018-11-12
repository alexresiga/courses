#!/bin/bash
b=5
c=6
var="Hello World"

str=$(date +%Y:%m:%d);
read b
read c
a=`expr $b + $c`

echo $a
