#!/bin/bash

read -p "choose option 1 (date), 2 (date and time) or 3 (exit): " var

case $var in
	1)
		echo "the date: $(date +%Y-%m-%d)";;
	2)
		echo "the date and time: $(date)";;
	3)
		echo "exit!!";;
	*)
		echo "valid option [1,2,3]";;
esac
