#!/bin/bash

if [ "$1" == "" ]; then
	echo "Provide a directory to test"

else
	for file in `ls $1`
	do
		cat ../scripts/$1/$file | ./compiler > assembly.asm
		echo "====== Running assembly.asm for $file ====="
		java -jar mars.jar nc assembly.asm
	done
fi
