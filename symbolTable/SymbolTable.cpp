#include <iostream>
#include <types/SimpleType.h>

#include "SymbolTable.h"
#include "Scope.h"
#include "../expressions/Literal.h"

SymbolTable::SymbolTable()
{
    nextAddress = 0;
    repeatLabelCounter = 0;
    whileLabelCounter = 0;
    nextLabelCounter = 0;
    nextForLabel = 0;
    nextIfLabel = 0;
    addingGlobals = true;

    // initialize symbol table with boolean constants constants
    std::string boolsLower[] = {"false", "true"};
    std::string boolsUpper[] = {"FALSE", "TRUE"};
    bool booleanLiterals[] = {false, true};
    auto booleanConstants = new std::vector<Constant*>();
    int NUM_BOOLS = 2;
    for (int i = 0; i < NUM_BOOLS; ++i)
    {
        booleanConstants->push_back(new Constant(boolsLower[i], new Literal(booleanLiterals[i])));
        booleanConstants->push_back(new Constant(boolsUpper[i], new Literal(booleanLiterals[i])));
    }

    // initialize symbol table with primitive types
    std::string primitivesLower[] = {"integer", "char", "string", "bool"};
    std::string primitivesUpper[] = {"INTEGER", "CHAR", "STRING", "BOOL"};
    auto primitiveTypes = new std::vector<DeclaredType*>();
    int NUM_PRIMITIVES = 4;
    for (int i = 0; i < NUM_PRIMITIVES; ++i)
    {
        primitiveTypes->push_back(new DeclaredType(primitivesLower[i], new SimpleType(&primitivesLower[i])));
        primitiveTypes->push_back(new DeclaredType(primitivesUpper[i], new SimpleType(&primitivesUpper[i])));
    }
    pushScope(Prelude(booleanConstants, primitiveTypes, new std::vector<TypedList*>()));
}

void SymbolTable::pushScope(Prelude prelude)
{
    Scope newScope = Scope();
    scopes.push_back(newScope);
    nextAddress += scopes.back().addConstructs(prelude, nextAddress);
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
    nextAddress -= scopes.back().getSize();
    scopes.pop_back();
}

void SymbolTable::addRoutines(std::vector<Routine*>* p_routines)
{
    for (Routine* routine : *p_routines)
    {
        routine->computeOffsets();
        routines[routine->ident] = routine;
    }
}

Routine* SymbolTable::retrieveRoutine(std::string name)
{
    if (routines.count(name) == 1) return routines[name];
    else throw std::runtime_error("SymbolTable::retrieveRoutine() - routine with name \"" + name + "\" not found in symbol table");
}

Entry SymbolTable::retrieveEntry(std::string key)
{
    int i = scopes.size() - 1;
    while (i != -1)
    {
        if (scopes[i].containsEntry(key)) return scopes[i].getEntry(key);
        else i--;
    }
    throw std::runtime_error("Entry with key \"" + key + "\" key not found in the symbol table");
}

BaseType* SymbolTable::retrieveType(std::string key)
{
    int i = scopes.size() - 1;
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

std::string SymbolTable::getNextNextLabel()
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

