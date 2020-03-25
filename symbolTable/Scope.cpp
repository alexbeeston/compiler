#include <iostream>
#include <string>

#include "Scope.h"
#include "../constructs/prelude/types/SimpleType.h"
#include "../constructs/expressions/BooleanLit.h"
#include "../RegisterPool.h"

extern RegisterPool rp;

// used during initialization
Scope::Scope(Prelude topLevelPrelude)
{

    // add boolean constants, implemented as redeclarable constants; they can't be variables because we need to pull their semantic value in const_declarations, but they can't be constants because we over write their value in badidea.cpsl
    int NUM_BOOLS = 2;
    std::string booleans[] = {"false", "true"};
    for (int i = 0; i < NUM_BOOLS; ++i) lookUpItems[booleans[i]] = LookUpItem(booleans[i], new BooleanLit(i), true);

    // add user defined constants
    for (Constant* i : *topLevelPrelude.constants) addItem(LookUpItem(i->ident, i->value, false));

//
//    // initialize with primitive types
//    std::string primitives[] = {"integer", "char", "string", "boolean"};
//    for (std::string primitive : primitives) types[std::string(primitive)] = SimpleType(new std::string(primitive));
//
//    // add user defined types
//    for (TypeDeclItem* type: *topLevelPrelude.types) types[*type->ident] = *type->type;
//
//    // add other variables
//    for (Variable* var : *topLevelPrelude.vars) addVariable(*var);
}

// used to handle LookUpItems (variables and constants)
//int Scope::addVariable(Variable &var)
//{
//    // check to make sure the type is in the symbol table
//   var.offset = nextAddress;
//   variables[var.ident] = var;
//   nextAddress += var.type.size;
//}
bool Scope::addItem(LookUpItem item)
{
    if (lookUpItems.count(item.ident) == 0)
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
