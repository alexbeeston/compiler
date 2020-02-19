#!/bin/bash
cmake ..
make

for file in ../scripts/*; do
	echo "Testing file $file"
	cat $file | ./calc
done

