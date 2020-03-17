#include <iostream>
#include <vector>

#include "constructs/Program.h"
#include "constructs/prelude/types/BaseType.h"
#include "constructs/prelude/types/SimpleType.h"
#include "symbolTable/SymbolTable.h"

extern int yyparse();
extern Program* program;
SymbolTable st;

int main()
{
	yyparse();
	std::cout << std::endl;


//	program->prettyPrint();
    st = SymbolTable(*program->prelude);
//	st.prettyPrint();
	program->emit();

	std::cout << "\n"; // do not move; we want to see PS1 after!
}
