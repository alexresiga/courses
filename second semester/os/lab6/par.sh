#! /bin/bash
> stats
cntF=0
cntD=0
while [ "$1" ]; do
	if [[ $1 =~ (0| [0-9][1-9]) ]]; then
		echo $1 >> file
	fi
	if [[ -f $1 ]]; then
		cntF=$(($cntF+1))
	fi
	if [[ -d $1 ]]; then
		cntD=$(($cntD+1))
	fi
	if [[ `cat users| grep $1` ]]; then
		user=`last | grep "\b$1\b" | grep Mon | awk '{print $1}' | uniq -c`
		echo $user >> stats
	fi
shift
done
echo $cntF files and $cntD directories
echo `cat stats | sort -r -k 1`
		
