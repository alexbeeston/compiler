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
            // If the type is in the symbol table, then we should use it for the variable. Otherwise, the type was declared inline, which is okay.
            BaseType* temp;
            if (types.count(*name) == 1) temp = types[*name];
            else temp = list->type;
            nextAddress += temp->size;
            addItem(LookUpItem(*name, *list->type, nextAddress));
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
    return lookUpItems[key];
}

// used to handle types

// validation
//void Scope::prettyPrint()
//{
//    std::cout << "\t Types:\n";
//    for( std::pair<std::string, BaseType> type: types)
//    {
//        std::cout << "\t\t" << type.first << " : " << "\n";
//    }
//
//    std::cout << "\t Constants/Variables, which have an expression:\n";
//    for (std::pair<std::string, Variable> item: variables )
//    {
//        std::cout << "\t\t" << "Identifier: " << item.first << "  Address: " << item.second.offset << "\n";
//    }
//
//    std::cout << "\t Functions:\n";
//    std::cout << "\t\t[placeholder]\n";
//}
