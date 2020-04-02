#include <iostream>
#include <string>

#include "Scope.h"
#include "../constructs/prelude/types/SimpleType.h"
#include "../constructs/expressions/Literal.h"
#include "../global.h"

extern RegisterPool rp;

// used during initialization
Scope::Scope(Prelude topLevelPrelude)
{
    // add boolean constants, implemented as redeclarable constants; they can't be variables because we need to pull their semantic value in const_declarations, but they can't be constants because we over write their value in badidea.cpsl
    int NUM_BOOLS = 2;
    std::string booleans[] = {"false", "true"};
    bool booleanLiterals[] = {false, true};
    for (int i = 0; i < NUM_BOOLS; ++i) entries[booleans[i]] = Entry(booleans[i], new Literal(booleanLiterals[i]), true);

    // add user defined constants
    for (Constant* i : *topLevelPrelude.constants) addEntry(Entry(i->ident, i->value, false));

    // initialize with primitive types
    std::string primitives[] = {"integer", "char", "string", "boolean"};
    for (std::string primitive : primitives)
    {
        addType(new SimpleType(&primitive, true));
        // don't have to set the size since a the names of the primitive types is the "name" field of the simple type, the simple type's lValueType gets set to PRIMITVE_TYPE
    }

    // add declared types
    for (BaseType* type : *topLevelPrelude.types)
    {
        type->size = computeSize(type);
        addType(type); // can I just replace this here with types[type->identifier]? // which should get replaced with types[typeDeclItem->identifier]
    }

    // add variables, which are all user defined
    for (TypedList* list: *topLevelPrelude.vars)
    {
        for (std::string* name: *list->identList)
        {
            addEntry(Entry(*name, list->type, nextAddress));
            std::cout << "# added variable " << *name << " at address " << nextAddress << "\n";
            nextAddress += computeSize(list->type);
        }
    }
}

int Scope::computeSize(BaseType* type)
{
    if (type->lValueType == PRIMITIVE_TYPE) return 4;
    else if (type->lValueType == ALIAS_TYPE)
    {
        if (types.count(type->identifier) == 1) return types[type->identifier]->size;
        else throw std::runtime_error("Can't find an ALIAS_TYPE in the symbol table");
    }
    else if (type->lValueType == ARRAY_TYPE) return computeSize_Array(dynamic_cast<ArrayType*>(type));
    else if (type->lValueType == RECORD_TYPE) return computeSize_Record(dynamic_cast<RecordType*>(type));
    else throw std::runtime_error("lValueType of type unknown\n");
}

int Scope::computeSize_Array(ArrayType* array)
{
    return 10;
}

int Scope::computeSize_Record(RecordType* record)
{
    return 10;
}


bool Scope::addEntry(Entry entry)
{
    if (entries.count(entry.ident) == 0) // replace with a single || statement
    {
        entries[entry.ident] = entry;
        return true;
    }
    else if (entries[entry.ident].isRedeclarable)
    {
       entries[entry.ident] = entry;
       return true;
    }
    else return false;
}

bool Scope::addType(BaseType* type)
{
    if (types.count(type->identifier) == 0)
    {
        types[type->identifier] = type;
        return true;
    }
    else if (types[type->identifier]->isRedeclarable)
    {
       types[type->identifier] = type;
       return true;
    }
    else
    {
        return true;
    }
}

BaseType* Scope::getBaseType(std::string key)
{
    // BUG: I (also) can't access the types map when I'm adding variables. It's not that I can't find the type in the map, it's, the map isn't accessbile
    return new BaseType();
}

Entry Scope::getEntry(std::string key)
{
    // BUG: I can't access the entries map when I'm adding arrays to the entry using const identifiers as bounds in the array; seems to be resolved
    return entries[key];
}