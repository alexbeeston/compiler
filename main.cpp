#include "miscellaneous/Program.h"
#include "symbolTable/SymbolTable.h"
#include "registerPool/RegisterPool.h"

extern int yyparse();
extern Program* program;
SymbolTable st;
RegisterPool rp;

int main()
{
	yyparse();
    st.pushScope(*program->prelude);
	program->emit();
}
