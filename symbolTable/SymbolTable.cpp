#include <iostream>

#include "SymbolTable.h"
#include "Scope.h"

SymbolTable::SymbolTable()
{
    levels.push_back(Scope());
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

