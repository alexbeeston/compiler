Build the project by navigating to calc/bld and running the shell script run.sh, which takes as a mandatory argument the name of a cpsl file to run. The script compiles the source code and pipes the output to mars.jar. It is assumed that a copy of mars.jar is in calc/bld (mars.jar is gitignored). You may add the optional flag -s after the file name to print out the assembly code that was emiited, or you may view this file latter in calc/bld/assembly.asm. In summary, after placing a copy of mars.jar in calc/bld and navigating to calc/bld, run a CPSL script with:

./run filename [-s]
