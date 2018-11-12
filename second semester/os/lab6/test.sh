#! /bin/bash
for x in `ls`; do
if [ -f $x ]; then
echo $x `cat $x | awk 'END{print NR}'` linii
fi
done
