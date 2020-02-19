#include "symbol_table.hpp"
#include "Program.h"
#include <iostream>

extern int yyparse();
extern Program program;

int main()
{
	symbol_table.enter_scope();
	yyparse();
}
