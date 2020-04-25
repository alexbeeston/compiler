#include <string>

#include "Scope.h"
#include "../global.h"

extern RegisterPool rp;

Scope::Scope() { }

int Scope::addConstructs(Prelude prelude, int nextAddress)
{
    int initialNextAddress = nextAddress;
    for (Constant* i : *prelude.constants) entries[i->ident] = Entry(i->ident, i->value);
    for (DeclaredType* declaredType : *prelude.declaredTypes) types[declaredType->identifier] = declaredType->type;
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
    return types.count(key) == 1;
}

BaseType* Scope::getType(std::string key)
{
    return types[key];
}

bool Scope::containsEntry(std::string key)
{
    return entries.count(key) == 1;
}

Entry Scope::getEntry(std::string key)
{
    return entries[key];
}

