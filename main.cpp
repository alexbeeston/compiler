#include <iostream>

#include "symbol_table.hpp"
#include "global.h"
#include "constructs/Program.h"
#include "constructs/Constant.h"

extern int yyparse();
extern Program program;
extern Constant* test;

int main()
{
	symbol_table.enter_scope();
	yyparse();
	std::cout << std::endl; // band-aid line; the terminal prints an extra tab without before the next PS1 line without it
	std::cout << "identifier: " << test->identifier << " value: " << test->value->value;
}
