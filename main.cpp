#include <iostream>

#include "routines/Program.h"
#include "symbolTable/SymbolTable.h"
#include "registerPool/RegisterPool.h"

extern int yyparse();
extern Program* program;
SymbolTable st;
RegisterPool rp;

int main()
{
	yyparse();
	std::cout << std::endl;
    st.pushScope(*program->prelude);
	program->emit();
	std::cout << "\n"; // do not move; we want to see PS1 after!
}
