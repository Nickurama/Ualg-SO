#!/bin/bash

for (( i=0; i<=$2; i++))
do
	result=$(($i * $1))
	echo "$i x $1 = $result"
done
