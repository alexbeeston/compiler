#include <iostream>
#include <string>

#include "Scope.h"
#include "../constructs/prelude/types/SimpleType.h"

Scope::Scope()
{
    types["dog"] = new SimpleType(new std::string("hello world"));

}

void Scope::prettyPrint()
{
    std::cout << "\t Constants:\n";
    for( std::pair<std::string, BaseType*> type: types)
    {
        std::cout << "\t\t" << type.first << " : ";
        type.second->print();
    }

}

void Scope::printTab()
{
    std::cout << "\t";
}