#!/bin/bash
make
cat $1 | ./compiler > assembly.asm
java -jar mars.jar nc assembly.asm
