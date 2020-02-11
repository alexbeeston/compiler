#include "symbol_table.hpp"
#include "Testing.h"
#include <iostream>

extern int yyparse();
extern int count;

int main()
{
//	Testing dog;
//	dog.num1 = 10;
//	dog.num2 = 20;
//	std::cout << dog.num1 << ", " << dog.num2 << std::endl;
	symbol_table.enter_scope();
	yyparse();
}
