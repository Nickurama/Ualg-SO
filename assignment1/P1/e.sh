#!/bin/bash

read -p "Expression: " expr

for file in $(ls)
do
	if [[ -f $file ]] && grep -q $expr $file
	then
		echo $file
	fi
done
