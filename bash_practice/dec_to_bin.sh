#!/bin/bash

dec=$1
bin=""

while [[ $dec -gt 0 ]]
do
	remainder=$((dec % 2))
	bin="$remainder$bin"
	(( dec /= 2 ))
done

echo $bin
