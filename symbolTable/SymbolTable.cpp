#include <iostream>
#include <types/SimpleType.h>

#include "SymbolTable.h"
#include "Scope.h"

SymbolTable::SymbolTable()
{
    nextAddress = 0;
    repeatLabelCounter = 0;
    whileLabelCounter = 0;
    nextLabelCounter = 0;
    nextForLabel = 0;
    nextIfLabel = 0;
    topScope = -1;
}

void SymbolTable::pushScope(Prelude prelude)
{
    int j = scopes.size();
    Scope newScope = Scope();
    topScope++;
    if (topScope > j - 1) scopes.push_back(newScope);
    else scopes[topScope] = newScope;
    nextAddress += scopes[topScope].addConstructs(prelude, nextAddress);
}

void SymbolTable::pushScope_iterator(std::string ident)
{
    std::string intString = "integer";
    auto* idents = new std::vector<std::string*>();
    idents->push_back(&ident);
    auto* typedList = new TypedList(idents, new SimpleType(&intString));
    auto* typedLists = new std::vector<TypedList*>();
    typedLists->push_back(typedList);
    Prelude p = Prelude(new std::vector<Constant*>, new std::vector<DeclaredType*>, typedLists);
    pushScope(p);
}

void SymbolTable::popScope()
{
    nextAddress -= scopes[topScope].getSize();
    topScope--;
}

void SymbolTable::prettyPrint()
{
    std::cout << "[implement SymbolTable::prettyPrint()]\n";
}

Entry SymbolTable::retrieveEntry(std::string key)
{
    int i = topScope;
    while (i != -1)
    {
        if (scopes[i].containsEntry(key)) return scopes[i].getEntry(key);
        else i--;
    }
    throw std::runtime_error("Entry with key \"" + key + "\" key not found in the symbol table");
}

BaseType* SymbolTable::retrieveType(std::string key)
{
    int i = topScope;
    while (i != -1)
    {
        if (scopes[i].containsType(key)) return scopes[i].getType(key);
        else i--;
    }
    throw std::runtime_error("Type with key \"" + key + "\" key not found in the symbol table");
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

