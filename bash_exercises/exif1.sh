#!/bin/bash

if [ -d $1 ]; then
	echo "the directory $1 exists"
else
	echo "the directory $1 does not exist"
fi
