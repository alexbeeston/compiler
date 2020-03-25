#include <iostream>
#include <string>

#include "Scope.h"
#include "../constructs/prelude/types/SimpleType.h"
#include "../constructs/expressions/Literal.h"
#include "../RegisterPool.h"

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
    for (std::string primitive :primitives) addType(new SimpleType(&primitive, primitive, true));

    // add user defined types
    for (BaseType* type: *topLevelPrelude.types) addType(type);

//    // add variables, which are all user defined
//    for (Variable* var : *topLevelPrelude.vars)
//    {
//        // here, we need to look up the type in the type map and assign the value of the key to this LookUpItem, or variable
//        TypeDeclItem = get
//        if (addItem(LookUpItem(var->ident, var->type, nextAddress))) nextAddress += var->type.size;
//    }
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
        std::cout << "# about to insert a redeclarable item.\n";
       lookUpItems[item.ident] = item;
       return true;
    }
    else return false;
}

bool Scope::addType(BaseType* type)
{
    if (types.count(type->identifier) == 0)
    {
        std::cout << "# case 1: " << type->identifier << " is not already in the map.\n";
        types[type->identifier] = type;
        return true;
    }
    else if (types[type->identifier]->isRedeclarable)
    {
        std::cout << "# case 2: " << type->identifier << " is aready in the map, but it's redeclarable.\n";
       types[type->identifier] = type;
       return true;
    }
    else
    {
        std::cout << "# case 3: " << type->identifier << " is already in the map and it's not redeclarable\n";
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
