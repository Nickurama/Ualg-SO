#!/bin/bash

read -p "select a start date: " start
read -p "select a end date: " end

find . -type f -newermt $start ! -newermt $end
