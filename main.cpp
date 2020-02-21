#include <iostream>

#include "symbol_table.hpp"
#include "global.h"
#include "constructs/Program.h"
#include "constructs/Constant.h"

extern int yyparse();
extern Program program;
extern std::vector<Constant*>* test;

int main()
{
	symbol_table.enter_scope();
	yyparse();
	std::cout << std::endl; // band-aid line; the terminal prints an extra tab without before the next PS1 line without it
	for (Constant* item : *test)
    {
	    std::cout << "Identifier: " << item->identifier << "  Value: " << item->value->value << std::endl; }
}
