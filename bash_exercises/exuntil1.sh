#!/bin/bash

c=1

until [ $c -eq 21 ]
do
	echo "value counter: $c"
	let "c=c+1"
done
