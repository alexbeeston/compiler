#include <iostream>
#include <string>

#include "symbol_table.hpp"
#include "global.h"
#include "constructs/Program.h"

#include "constructs/routines/Function.h" // for sandbox only
extern int yyparse();
extern Program program;

int main()
{
//	Routine* a = new Function();
//	a->print();

	symbol_table.enter_scope();
	yyparse();
	std::cout << std::endl; // band-aid line; the terminal prints an extra tab without before the next PS1 line without it
	program.prettyPrint();
}
