#include <iostream>

#include "SymbolTable.h"
#include "Scope.h"
#include "../expressions/Literal.h"
#include "../types/SimpleType.h"
#include "../global.h"

SymbolTable::SymbolTable()
{
    repeatLabelCounter = 0;
    whileLabelCounter = 0;
    nextNextLabelCounter = 0;
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
    auto prelude = Prelude(booleanConstants, primitiveTypes, new std::vector<TypedList*>());
    pushScope(nullptr, std::vector<ParameterSet*>(), prelude);
}

void SymbolTable::pushScope(BaseType* returnType, std::vector<ParameterSet*> parameters, Prelude prelude)
{
    Scope newScope = Scope();
    scopes.push_back(newScope);
    if (returnType != nullptr) scopes.back().accommodateReturnType(returnType);
    scopes.back().addEntriesFromParameters(parameters);
    scopes.back().addEntriesFromPrelude(prelude);
}

void SymbolTable::popScope()
{
    scopes.back().getSizeOfDeclaredVars();
    scopes.pop_back();
}

void SymbolTable::addRoutines(std::vector<Method*>* p_routines)
{
    for (Method* methods : *p_routines)
    {
        if (routines.count(methods->ident) == 1)
        {
            Method* st_routine = routines[methods->ident];
            if (st_routine->isForwardDeclared)
            {
                st_routine->body = methods->body;
                st_routine->isForwardDeclared= false;
            }
            else throw std::runtime_error("SymbolTable::addRoutines() - methods with name \"" + methods->ident + "\" already in symbol table and is not forward declared");
        }
        else
        {
            methods->computeOffsetsAndPassBys();
            routines[methods->ident] = methods;
        }
    }
}

Method* SymbolTable::retrieveRoutine(std::string name)
{
    if (routines.count(name) == 1) return routines[name];
    else throw std::runtime_error("SymbolTable::retrieveRoutine() - routine with name \"" + name + "\" not found in symbol table");
}

bool SymbolTable::containsEntry(std::string key)
{
    int i = scopes.size() - 1;
    while (i != -1)
    {
        if (scopes[i].containsEntry(key)) return true;
        else i--;
    }
    return false;
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

void SymbolTable::addIterator(std::string identifier)
{
    Entry iterator = Entry(identifier, new SimpleType(new std::string("integer")), nextGlobalAddress, true, true, false);
    nextGlobalAddress += WORD_SIZE;
    scopes.back().entries[identifier] = iterator;
}

void SymbolTable::removeIterator(std::string identifier)
{
    nextGlobalAddress -= WORD_SIZE;
    scopes.back().entries.erase(identifier);
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
    nextNextLabelCounter++;
    return std::string("n" + std::to_string(nextNextLabelCounter));
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

