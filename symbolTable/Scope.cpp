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

int Scope::addConstructs(Prelude topLevelPrelude)
{
    // add boolean constants
    int NUM_BOOLS = 2;
    std::string booleans[] = {"false", "true"};
    bool booleanLiterals[] = {false, true};
    for (int i = 0; i < NUM_BOOLS; ++i) entries[booleans[i]] = Entry(booleans[i], new Literal(booleanLiterals[i]));

    // add user defined constants
    for (Constant* i : *topLevelPrelude.constants) entries[i->ident] = Entry(i->ident, i->value);

    // initialize with primitive types
    std::string primitives[] = {"integer", "char", "string", "bool"};
    for (std::string primitive : primitives) types[primitive] = new SimpleType(&primitive); // todo: add a key for uppercase

    // add declared types
    for (DeclaredType* declaredType : *topLevelPrelude.declaredTypes) types[declaredType->identifier] = declaredType->type;

    // add variables, which are all user defined
    for (TypedList* list: *topLevelPrelude.vars)
    {
        for (std::string* name: *list->identList)
        {
            entries[*name] = Entry(*name, list->type, nextAddress);
            std::cout << "# added " << *name << " at " << nextAddress << "\n";
            nextAddress += list->type->computeSize();
        }
    }
    return nextAddress;
}

BaseType* Scope::getBaseType(std::string key)
{
    if (types.count(key) == 1) return types[key];
    else throw std::runtime_error("Type with identifier \"" + key + "\" not found in symbol table");
}

Entry Scope::getEntry(std::string key)
{
    if (containsEntry(key)) return entries[key];
    else throw std::runtime_error("Entry with identifier \"" + key + "\" not found in symbol table");
}

bool Scope::containsEntry(std::string key)
{
    if (entries.count(key) == 1) return true;
    else return false;
}