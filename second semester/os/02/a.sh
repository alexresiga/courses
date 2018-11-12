#!/bin/bash
for f in `find /Users/Alex/SO`; do
	if [ ! -f $f ]; then
		continue
	fi
	u=`ls -l $f|cut -d' ' -f4`
	s=`ls -l $f|cut -d' ' -f8`
	if [ $s -gt 1000 ]; then
		echo $u
	fi
done | sort | uniq
