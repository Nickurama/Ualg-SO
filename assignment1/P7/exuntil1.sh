#!/bin/bash

i=0
until [ $i -eq 20 ]
do
	((i++))
	echo $i
done
