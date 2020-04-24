## Overview
This program is a compiler for a toy language used in CS5300 at Utah State University. Sample source scripts can be found in scripts/. The build instructions assume the user in on Linux.

## Build Instructions
Build the compiler with cmake by doing the following:
1) create a build directory
2) cd into this directory
3) run cmake with the command "cmake .."
4) run make with the command "make"

This will produce an executable named "compiler", which reads from standard in and writes to standard out. Note that Flex and Bison generate the scanner and parser and store them in the directory from step 1. For this reason, only the grammar files scanner.l and parser.y are included in the repository. Install flex and bison before building.

## Instructions to compile and run a source script
Once the compiler is built, compile a sample script by piping the script into the compiler, then redirecting the output to a file. For example, if the build directory from step 1 was named "bld", to compile the file scripts/simple_expressions/hello.cpsl to the file assembly.asm, run the command "cat scripts/simple_expressions/hello.cpsl | bld/compiler > assembly.asm". Run "assembly.asm" with a MIPS simulator, such as MARS. If mars.jar is in the working directory, run "assembly.asm" with the command "java -jar mars.jar assembly.asm".
