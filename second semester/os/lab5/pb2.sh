#!/bin/bash
# prefix si cuvintele care contin prefixul

prefix=$1;
shift;

for var in $*; do
if [[ $var=~^\$prefix ]]; then
echo $var
fi
done

