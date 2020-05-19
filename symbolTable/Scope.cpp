#include <string>

#include "Scope.h"
#include "../global.h"
#include <cmath>

extern RegisterPool rp;

Scope::Scope()
{
    nextDeclaredVariableAddress = 0;
    nextSignatureVariableAddress = 0;
}

void Scope::accommodateReturnType(BaseType* type)
{
    nextSignatureVariableAddress += type->computeSize();
}

void Scope::addEntriesFromParameters(std::vector<ParameterSet*> parameterSets)
{
    static bool IS_DECLARED = false;
    bool passByReference;
    for (auto set : parameterSets)
    {
        if (set->passBy == REFERENCE)  passByReference = true;
        else passByReference = false;
        int size = set->type->computeSize();
        for (std::string identifier : set->identList)
        {
            entries[identifier] = Entry(identifier, set->type, nextSignatureVariableAddress, st.addingGlobals, IS_DECLARED, passByReference);
            nextSignatureVariableAddress += size;
        }
    }
}

void Scope::addEntriesFromPrelude(Prelude prelude)
{
    static bool IS_DECLARED = true;
    static bool IS_PASS_BY_REFERENCE = false;
    for (Constant* i : *prelude.constants) entries[i->ident] = Entry(i->ident, i->value, st.addingGlobals, IS_DECLARED);
    for (DeclaredType* declaredType : *prelude.declaredTypes) types[declaredType->identifier] = declaredType->type;
    for (TypedList* list: *prelude.vars)
    {
        int size = list->type->computeSize();
        for (std::string* name: *list->identList)
        {
            if (st.addingGlobals)
            {
                entries[*name] = Entry(*name, list->type, nextDeclaredVariableAddress, st.addingGlobals, IS_DECLARED, IS_PASS_BY_REFERENCE);
                std::cout << "# added " << *name << " at " << nextDeclaredVariableAddress << "\n";
                nextDeclaredVariableAddress += size;
            }
            else
            {
                nextDeclaredVariableAddress -= size;
                entries[*name] = Entry(*name, list->type, nextDeclaredVariableAddress, st.addingGlobals, IS_DECLARED, IS_PASS_BY_REFERENCE);
                std::cout << "# added " << *name << " at " << nextDeclaredVariableAddress << "\n";
            }
        }
    }
}

int Scope::getSizeOfDeclaredVars() { return std::abs(nextDeclaredVariableAddress); }

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

