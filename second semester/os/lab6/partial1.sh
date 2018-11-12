#! /bin/bash

cnt=0
while [ $cnt -lt 5 ]; do
read user
if [[ `who | grep $user` ]]; then
	cnt=$(($cnt+1))
fi
done

