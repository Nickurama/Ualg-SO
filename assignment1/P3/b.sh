#!/bin/bash

read -p "file 1: " file1
read -p "file 2: " file2
cat $file1 >> file3.txt
cat $file2 >> file3.txt
cat file3.txt | wc -l
