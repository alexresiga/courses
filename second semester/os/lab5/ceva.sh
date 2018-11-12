#!/bin/bash

for var in $*; do
echo $var;
done

while [ $# -ne 0 ]; do
echo $1;
shift;
done
