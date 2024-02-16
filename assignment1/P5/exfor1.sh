#!/bin/bash

for dir in /bin /etc
do
	echo "${dir}: "
	ls $dir
	sleep 2
done	
