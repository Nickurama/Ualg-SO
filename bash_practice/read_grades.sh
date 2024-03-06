#!/bin/bash

if [ -z "$1" ]
then
	read -p "What file do you want to read? " input
else
	input=$1
fi


if [[ -f $input ]]
then
	cat $input | while read line
	do
		counter=0
		name=""
		sum=0
		for word in $line
		do
			if [[ $counter -eq 0 ]]
			then
				name="$word"
			else
				((sum += $word))
			fi
			((counter++))
		done
		(( grade = sum / (counter - 1)))
		echo "$name $grade"
	done
else
	echo "file doesn't exist"
fi
