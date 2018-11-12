#!/bin/bash

while [ "$1" ]
do
var=`ls -l $1 | awk '{print $5}'`
echo $var
if [ $2 -eq $var ]; then
echo "$1 size is $2"
else
echo "$1 is not file"
fi
shift 2
done

