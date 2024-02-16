#!/bin/bash

read -p "current extension: " curr_ext
read -p "new extension: " new_ext

for file in $(find . -regex ".*\.${curr_ext}")
do
	filename="${file##*/}"
	prefix="${filename%.*}"
	mv $filename "${prefix}.${new_ext}"
done
