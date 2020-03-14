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


	program->prettyPrint();
	SymbolTable st = SymbolTable(*program->prelude);
	st.prettyPrint();

	program->emit();



	std::cout << "\n"; // do not move; we want to see PS1 after!
}
