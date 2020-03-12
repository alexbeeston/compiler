#include <iostream>
#include <vector>

#include "global.h"
#include "constructs/Program.h"
#include "symbolTable/SymbolTable.h"

#include "constructs/prelude/types/BaseType.h"
#include "constructs/prelude/types/SimpleType.h"

extern int yyparse();
extern Program* program;

int main()
{
	yyparse();
	std::cout << std::endl;

	SymbolTable st = SymbolTable(*program->prelude);

	std::cout << ".txt\n";
	std::cout << ".globl main\n";
	std::cout << "main:\n";
	std::cout << "li $v0, 11\n";
	std::cout << "la $a0, 'a'\n";
	std::cout << "syscall\n";
	std::cout << "li $v0, 10\n";
	std::cout << "syscall\n";

}
