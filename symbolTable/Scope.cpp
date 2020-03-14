#include <iostream>
#include <string>

#include "Scope.h"
#include "../constructs/prelude/types/SimpleType.h"
#include "../constructs/expressions/Expression.h"

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

    // add variables
    if (topLevelPrelude.vars != nullptr)
    {
        // check to make sure the type is in the symbol table already
        for (Variable* var : *topLevelPrelude.vars)
        {

        }
    }
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