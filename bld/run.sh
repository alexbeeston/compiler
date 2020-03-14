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

echo "===== Compiling to assembly.asm ====="
cat $1 | ./calc > assembly.asm
echo "====== Running assembly.asm ====="
java -jar mars.jar nc assembly.asm
echo "===== std::cout ====="
cat assembly.asm
