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

LookUpItem SymbolTable::retrieveItem(std::string key)
{
    return levels[0].getLookUpItem(key); // assumes it's in the first scope
}

int SymbolTable::insertMessage(std::string message)
{
    strings.push_back(message);
    return strings.size() - 1;
}

void SymbolTable::testPrint() {std::cout << "Access to a symbol table.\n";}
