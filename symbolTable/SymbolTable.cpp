#include <iostream>

#include "SymbolTable.h"
#include "Scope.h"

SymbolTable::SymbolTable()
{
    repeatLabelCounter = 0;
    whileLabelCounter = 0;
    nextLabelCounter = 0;
}

void SymbolTable::addStuff(Prelude topLevelPrelude)
{
    levels.push_back(Scope());
    levels[0].addConstructs(topLevelPrelude);
}

void SymbolTable::prettyPrint()
{
    int levelCounter = 0;
    for (Scope scope : levels)
    {
        std::cout << "Scope Level " << levelCounter << "\n";
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

std::string SymbolTable::getRepeatLabel()
{
    repeatLabelCounter++;
    return std::string("r" + std::to_string(repeatLabelCounter));
}

std::string SymbolTable::getWhileLabel()
{
    whileLabelCounter++;
    return std::string("w" + std::to_string(whileLabelCounter));
}

std::string SymbolTable::getNextLabel()
{
    nextLabelCounter++;
    return std::string("n" + std::to_string(nextLabelCounter));
}

void SymbolTable::testPrint() {std::cout << "Access to a symbol table.\n";}












