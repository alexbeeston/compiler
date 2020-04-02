#include <iostream>

#include "BaseType.h"


BaseType::BaseType()
{
}

void BaseType::print()
{
    std::cout << "[base type]";
}

int BaseType::computeSize()
{
    throw std::runtime_error("Can't call computeSize on a BaseType object");
}

TypeIndicator BaseType::getTypeIndicator() { return typeIndicator; }
