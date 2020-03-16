#include <iostream>
#include <string>

#include "Scope.h"
#include "../constructs/prelude/types/SimpleType.h"
#include "../constructs/expressions/Expression.h"

Scope::Scope(Prelude topLevelPrelude)
{
    // add constants
//    if (topLevelPrelude.constants != nullptr)
//    {
//        for (Constant* constant : *topLevelPrelude.constants)
//        {
//            expressions[*constant->identifier] = *constant->value;
//        }
//    }

    // initialize with primitive types
    std::string primitives[] = {"integer", "char", "boolean", "string", "true", "false"};
    for (std::string primitive : primitives)
    {
        types[std::string(primitive)] = SimpleType(new std::string(primitive));
    }

    // add types
    if (topLevelPrelude.types != nullptr)
    {
        for (TypeDeclItem* type: *topLevelPrelude.types)
        {
            types[*type->ident] = *type->type;
        }
    }

    // add variables
    if (topLevelPrelude.vars != nullptr)
    {
        int address = 0;
        for (Variable* var : *topLevelPrelude.vars)
        {
            // check to make sure the type is in the symbol table
            var->address = address;
            variables[var->ident] = *var;
            address += var->type.size;
        }
    }
}

Variable Scope::lookUpVariable(std::string key)
{
   // do something like variables.find(key) !-= variables.end();
   return variables[key]; // assumes that the key exists
}

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
        std::cout << "\t\t" << "Identifier: " << item.first << "  Address: " << item.second.address << "\n";
    }

    std::cout << "\t Functions:\n";
    std::cout << "\t\t[placeholder]\n";
}
