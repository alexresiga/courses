#! /bin/bash
#primeste oricate directoare ca parametrii si afiseaza pentru fiecare Director <numeDirector> - executabile: y -ne-executabile: z directoare: t

while [ "$1" ]; do
	if [ -d $1 ]; then
		cntE=0
		cntN=0
		cntD=0
		for x in `ls $1`; do
			dir=`file $x | grep directory`
			if [ -n "$dir" ]; then
				cntD=$(($cntD+1))
			fi
			if [ -x $x ]; then
				cntE=$(($cntE+1))
			fi
			if [ ! -x $x ]; then
				cntN=$(($cntN+1))
			fi
		done
	echo Director $1 
	echo - executabile: $cntE
	echo - ne-executabile: $cntN
	echo - directoare: $cntD
	else
		echo $1 nu e director
	fi
shift
done
