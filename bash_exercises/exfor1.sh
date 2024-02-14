#!/bin/bash

for dir in /bin /etc; do
	echo "Content of $dir: "
	sleep 2
	ls "$dir"
	sleep 2
done
cd ~
