#!/bin/bash

sum()
{
	let "s=$n1+$n2"
	echo "Result: $s"
}

read -p "first number: " n1
read -p "second number: " n2

sum $n1 $n2
