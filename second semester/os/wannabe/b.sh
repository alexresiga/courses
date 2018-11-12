#!/bin/bash

for x in `ls`; do
var=`grep .txt $x`
if [ $var -gt 0 ]; then
word=`cat $x | grep \bcat\b`
if [ $word -gt 0 ]; then
echo $x
fi
fi
done

