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
    // add user defined constants
    for (Constant* i : *topLevelPrelude.constants) if (constants.count(i->ident) == 0) constants[i->ident] = *i;

    // add boolean constants if they are not already defined
    int NUM_BOOLS = 2;
    std::string booleans[] = {"false", "true"};
    for (int i = 0; i < NUM_BOOLS; ++i) if (constants.count(booleans[i]) == 0) constants[booleans[i]] = Constant(booleans[i], new BooleanLit(i));

    // initialize with primitive types
    std::string primitives[] = {"integer", "char", "string", "boolean"};
    for (std::string primitive : primitives) types[std::string(primitive)] = SimpleType(new std::string(primitive));

    // add user defined types
    for (TypeDeclItem* type: *topLevelPrelude.types) types[*type->ident] = *type->type;

    // add other variables
    for (Variable* var : *topLevelPrelude.vars) addVariable(*var);
}

// used to handle LookUpItems (variables and constants)
int Scope::addVariable(Variable &var)
{
    // check to make sure the type is in the symbol table
   var.offset = nextAddress;
   variables[var.ident] = var;
   nextAddress += var.type.size;
}

LookUpItem Scope::getLookUpItem(std::string key)
{
    if (constants.count(key) == 1) return constants[key];
    else if (variables.count(key) == 1) return variables[key];
    else
    {
        std::cout << "error: lookUpItem is not in the symbol table.";
        return LookUpItem();
    }
}

// used to handle types

// validation
void Scope::prettyPrint()
{
    std::cout << "\t Types:\n";
    for( std::pair<std::string, BaseType> type: types)
    {
        std::cout << "\t\t" << type.first << " : " << "\n";
    }

    std::cout << "\t Constants/Variables, which have an expression:\n";
    for (std::pair<std::string, Variable> item: variables )
    {
        std::cout << "\t\t" << "Identifier: " << item.first << "  Address: " << item.second.offset << "\n";
    }

    std::cout << "\t Functions:\n";
    std::cout << "\t\t[placeholder]\n";
}
