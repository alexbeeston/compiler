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
    for (int i = 0; i < NUM_BOOLS; ++i) lookUpItems[booleans[i]] = LookUpItem(booleans[i], new Literal(booleanLiterals[i]), true);

    // add user defined constants
    for (Constant* i : *topLevelPrelude.constants) addItem(LookUpItem(i->ident, i->value, false));

    // initialize with primitive types
    std::string primitives[] = {"integer", "char", "string", "boolean"};
    for (std::string primitive : primitives) addType(new SimpleType(&primitive, true));

    // add user defined types
    for (BaseType* type: *topLevelPrelude.types) addType(type);

    // add variables, which are all user defined
    for (TypedList* list: *topLevelPrelude.vars)
    {
        for (std::string* name: *list->identList)
        {
            // method one: if the type is in the symbol table, pull it; otherwise, just use the type declared inline. THIS MAY NOT BE NECESSARY
            BaseType* temp;
            if (types.count(list->type->identifier) == 1) temp = types[list->type->identifier]; // probably only necessary when the type is primitive
            else temp = list->type;
            addItem(LookUpItem(*name, temp , nextAddress));
            nextAddress += temp->computeSize();

//            // method two: just add the type (preferred for its simplicity; results in seg fault, but seems like it should work. Consider later. Possible downside too is that there might be many instances of a primitive types
//            nextAddress += list->type->computeSize();
//            addItem(LookUpItem(*name, *list->type, nextAddress));
        }
    }
}

bool Scope::addItem(LookUpItem item)
{
    if (lookUpItems.count(item.ident) == 0) // replace with a single || statement
    {
        lookUpItems[item.ident] = item;
        return true;
    }
    else if (lookUpItems[item.ident].isRedeclarable)
    {
       lookUpItems[item.ident] = item;
       return true;
    }
    else return false;
}

bool Scope::addType(BaseType* type) // consider the case for records and arrays, which will have another type, which will need to be looked up in the symbol table or declared in-line. Save for later with UDD
{ // assumes for now no arrays nor records
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
    return types[key];
}

LookUpItem Scope::getLookUpItem(std::string key)
{
    // BUG: I can't access the lookUpItems map when I'm adding arrays to the lookUpItem using const identifiers as bounds in the array.
    return lookUpItems[key];
}