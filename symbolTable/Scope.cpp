#include <iostream>
#include <string>

#include "Scope.h"
#include "../constructs/prelude/types/SimpleType.h"

Scope::Scope(Prelude topLevelPrelude)
{
    // add constants
    if (topLevelPrelude.constants != nullptr)
    {
        for (Constant* constant : *topLevelPrelude.constants)
        {
            expressions[*constant->identifier] = *constant->value;
        }
    }

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

    // add variables to a scope - I guess for each variable, we just check to make sure that is
    // has a valid type, and then add it to the expressions map with a new Expression
}

void Scope::prettyPrint()
{
    std::cout << "\t Constants/Variables, which have an expressions:\n";
    for (std::pair<std::string, Expression> item: expressions)
    {
        std::cout << "\t\t" << item.first << "\n";
    }
    std::cout << "\t Types:\n";
    for( std::pair<std::string, BaseType> type: types)
    {
        std::cout << "\t\t" << type.first << " : " << "\n";
    }
    std::cout << "\t Functions:\n";
    std::cout << "\t\t[placeholder]\n";
}

void Scope::printTab()
{
    std::cout << "\t";
}