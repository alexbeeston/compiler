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
}
