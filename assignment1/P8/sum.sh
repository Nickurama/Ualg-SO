#!/bin/bash

sum ()
{
	sum=$(($1+$2))
	echo $sum
}

echo "Result: $(sum $1 $2)"
