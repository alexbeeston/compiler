#!/bin/bash
cmake ..
make

# if [ "$1" == "" ]; then
# 	for file in ../scripts/*; do
#		echo "##########"
#	echo "$file"
#		cat $file | ./calc 
#	done
#else
#	cat $1 | ./calc > 
#fi

cat $1 | ./calc > assembly.asm
java -jar mars.jar nc assembly.asm
