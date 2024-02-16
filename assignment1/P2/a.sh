#!/bin/bash

factorial ()
{
	if [ $1 -le 1 ]
	then
		echo $1
	else
		echo $(($1 * $(factorial $(($1 - 1)))))
	fi
}

echo $(factorial $1)
