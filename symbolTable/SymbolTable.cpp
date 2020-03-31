#include <iostream>

#include "SymbolTable.h"
#include "Scope.h"

SymbolTable::SymbolTable() {}

void SymbolTable::addStuff(Prelude topLevelPrelude)
{
    levels.push_back(Scope(topLevelPrelude));
}


void SymbolTable::prettyPrint()
{
    int levelCounter = 0;
    for (Scope scope : levels)
    {
        std::cout << "Scope Level " << levelCounter << "\n";
//        scope.prettyPrint();
    }
}

Entry SymbolTable::retrieveEntry(std::string key)
{
    return levels[0].getEntry(key); // assumes it's in the first scope
}

BaseType* SymbolTable::retrieveType(std::string key)
{
    return levels[0].getBaseType(key); // assumes it's in the first scope
}

int SymbolTable::insertMessage(std::string message)
{
    strings.push_back(message);
    return strings.size() - 1;
}

void SymbolTable::testPrint() {std::cout << "Access to a symbol table.\n";}
