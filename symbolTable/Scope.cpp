#include <iostream>
#include <string>

#include "Scope.h"
#include "../constructs/prelude/types/SimpleType.h"

Scope::Scope()
{
    std::string primitives[] = {"integer", "char", "boolean", "string", "true", "false"};
    for (std::string primitive : primitives)
    {
        types[std::string(primitive)] = new SimpleType(new std::string(primitive));
    }

}

void Scope::prettyPrint()
{
    std::cout << "\t Constants:\n";
    for( std::pair<std::string, BaseType*> type: types)
    {
        std::cout << "\t\t" << type.first << " : ";
        type.second->print();
        std::cout << "\n";
    }

}

void Scope::printTab()
{
    std::cout << "\t";
}