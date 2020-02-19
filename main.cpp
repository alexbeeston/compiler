#include "symbol_table.hpp"
#include "Program.h"
#include "global.h"
#include <iostream>

extern int yyparse();
extern Program program;

int main()
{
	symbol_table.enter_scope();
	yyparse();
	std::cout << std::endl; // band-aid line; the terminal prints an extra tab without before the next PS1 line without it
}
