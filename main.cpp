#include <iostream>

#include "global.h"
#include "constructs/Program.h"
#include "symbolTable/SymbolTable.h"


extern int yyparse();
extern Program* program;

int main()
{
	yyparse();
	std::cout << std::endl;

	SymbolTable st = SymbolTable(*program->prelude);
    st.prettyPrint();
}
