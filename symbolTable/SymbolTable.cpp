#include <iostream>

#include "SymbolTable.h"
#include "Scope.h"

SymbolTable::SymbolTable() {}

SymbolTable::SymbolTable(Prelude topLevelPrelude)
{
    levels.push_back(Scope(topLevelPrelude));
}


void SymbolTable::prettyPrint()
{
    int levelCounter = 0;
    for (Scope scope : levels)
    {
        std::cout << "Scope Level " << levelCounter << "\n";
        scope.prettyPrint();
    }
}

Variable SymbolTable::retrieveVariable(std::string key)
{
    return levels[0].lookUpVariable(key); // assumes it's in the first scope
}

void SymbolTable::testPrint() {std::cout << "Access to a symbol table.\n";}
