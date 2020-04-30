#include <string>

#include "Scope.h"
#include "../global.h"
#include <cmath>

extern RegisterPool rp;

Scope::Scope() { nextAddress = 0; }

void Scope::accommodateReturnType(BaseType* type)
{
    updateNextAddress(type->computeSize());
}

void Scope::addParameters(std::vector<ParameterSet*> parameterSets)
{
    for (auto set : parameterSets)
    {
        int size = set->type->computeSize();
        for (std::string identifier : set->identList)
        {
            Entry var = Entry(identifier, set->type, nextAddress, st.addingGlobals);
            updateNextAddress(size);
        }
    }
}

void Scope::addLocalPrelude(Prelude prelude)
{
    for (Constant* i : *prelude.constants) entries[i->ident] = Entry(i->ident, i->value, st.addingGlobals);
    for (DeclaredType* declaredType : *prelude.declaredTypes) types[declaredType->identifier] = declaredType->type;
    for (TypedList* list: *prelude.vars)
    {
        int size = list->type->computeSize();
        for (std::string* name: *list->identList)
        {
            entries[*name] = Entry(*name, list->type, nextAddress, st.addingGlobals);
            updateNextAddress(size);
        }
    }
}

void Scope::updateNextAddress(int amount)
{
    if (st.addingGlobals) nextAddress += amount;
    else nextAddress -= amount;
}

int Scope::getSize() { return std::abs(nextAddress); }

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

