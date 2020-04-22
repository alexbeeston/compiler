#include <iostream>
#include <string>

#include "Scope.h"
#include "../constructs/prelude/types/SimpleType.h"
#include "../constructs/prelude/types/DeclaredType.h"
#include "../constructs/expressions/Literal.h"
#include "../constructs/expressions/LValueExpression.h"
#include "../global.h"

extern RegisterPool rp;

Scope::Scope() { }

int Scope::addConstructs(Prelude prelude, int nextAddress)
{
    int initialNextAddress = nextAddress;
    // add boolean constants
    int NUM_BOOLS = 2;
    std::string booleans[] = {"false", "true"};
    bool booleanLiterals[] = {false, true};
    for (int i = 0; i < NUM_BOOLS; ++i) entries[booleans[i]] = Entry(booleans[i], new Literal(booleanLiterals[i]));

    // add user defined constants
    for (Constant* i : *prelude.constants) entries[i->ident] = Entry(i->ident, i->value);

    // initialize with primitive types
    std::string primitivesLower[] = {"integer", "char", "string", "bool"};
    for (std::string primitive : primitivesLower) types[primitive] = new SimpleType(&primitive);
    std::string primitivesUpper[] = {"INTEGER", "CHAR", "STRING", "BOOL"};
    int NUM_PRIMITIVES = 4;
    for (int i = 0; i < NUM_PRIMITIVES; i++) types[primitivesUpper[i]] = new SimpleType(&primitivesLower[i]);

    // add declared types
    for (DeclaredType* declaredType : *prelude.declaredTypes) types[declaredType->identifier] = declaredType->type;

    // add variables, which are all user defined
    for (TypedList* list: *prelude.vars)
    {
        for (std::string* name: *list->identList)
        {
            entries[*name] = Entry(*name, list->type, nextAddress);
            nextAddress += list->type->computeSize();
        }
    }
    size = nextAddress - initialNextAddress;
    return nextAddress;
}

int Scope::getSize() { return size; }

bool Scope::containsType(std::string key)
{
    if (types.count(key) == 1) return true;
    else return false;
}

BaseType* Scope::getType(std::string key)
{
    return types[key];
}

bool Scope::containsEntry(std::string key)
{
    if (entries.count(key) == 1) return true;
    else return false;
}

Entry Scope::getEntry(std::string key)
{
    return entries[key];
}

