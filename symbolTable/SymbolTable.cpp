#include <iostream>

#include "SymbolTable.h"
#include "Scope.h"

SymbolTable::SymbolTable()
{
    repeatLabelCounter = 0;
    whileLabelCounter = 0;
    nextLabelCounter = 0;
    nextForLabel = 0;
    nextAvailableAddress = 0;
    nextIfLabel = 0;
}

void SymbolTable::addStuff(Prelude topLevelPrelude)
{
    levels.push_back(Scope());
    nextAvailableAddress += levels[0].addConstructs(topLevelPrelude);
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

std::string SymbolTable::getNextForLabel()
{
    nextForLabel++;
    return std::string("f" + std::to_string(nextForLabel));
}

std::string SymbolTable::getNextIfLabel()
{
    nextIfLabel++;
    return std::string("i" + std::to_string(nextIfLabel));
}

bool SymbolTable::containsEntry(std::string key)
{
   return levels[0].containsEntry(key); // assume it's in the first scope
}

int SymbolTable::getNextAvailableAddress() { return nextAvailableAddress; }

void SymbolTable::incrementNextAvailableAddress(int increase) { nextAvailableAddress += increase; }

void SymbolTable::testPrint() {std::cout << "Access to a symbol table.\n";}












