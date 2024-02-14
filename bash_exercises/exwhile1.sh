#!/bin/bash

c=1

while [ $c -le 20 ] ;
do
	echo "value counter: $c"
	((c++))
done
