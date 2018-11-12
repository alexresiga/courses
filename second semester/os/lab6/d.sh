#un cuvant si un numar, citeste de la tastatura nume de fisiere pana cand se intalneste un fisier care nu exista. Sa se afiseze cate dintre fisierele citite contin cuvantul de cel putin numar ori

#!/bin/bash

cuvant=$1
n=$2
count=0

read file
while [ -f $file ]; do
	#cuv=$(awk "BEGIN{cnt=0}{for(i=1;i<=NF;i++) if (\$i ~ /\b$cuvant\b/) cnt++} END{print cnt}" $file)
	cuv=` cat $file | grep -o "\b$cuvant\b" | wc -l`
	echo $cuv
	if [ $cuv -ge $n ]; then
		count=$(($count +1))
	fi
	echo citit $file
read file
done
echo $count
