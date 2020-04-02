#include <iostream>
#include <vector>

#include "constructs/Program.h"
#include "constructs/prelude/types/BaseType.h"
#include "constructs/prelude/types/SimpleType.h"
#include "symbolTable/SymbolTable.h"
#include "RegisterPool.h"

#include <map>

extern int yyparse();
extern Program* program;
SymbolTable st;
RegisterPool rp;

int main()
{
	yyparse();
	std::cout << std::endl;
    st.addStuff(*program->prelude); // it appears that the constructors on the symbol table and register pool are automatically being called
	program->emit();

	std::cout << "\n"; // do not move; we want to see PS1 after!

//    std::map<int, std::string> test = std::map<int, std::string>();
//    test[10] = "hello\n";
//    std::cout << test[10];
//    test[10] = "goodbye\n";
//
//    std::cout << "Size of map; " << test.size() << "\n";
}
