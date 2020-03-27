#include <iostream>

#include "BaseType.h"


BaseType::BaseType()
{
}

void BaseType::print()
{
    std::cout << "[base type]";
}

int BaseType::computeSize() { throw std::runtime_error("Calling computeSize() on the baseType\n"); }
