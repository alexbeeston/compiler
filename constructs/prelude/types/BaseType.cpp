#include <iostream>

#include "BaseType.h"


BaseType::BaseType()
{
}

void BaseType::print()
{
    std::cout << "[base type]";
}

int BaseType::computeSize() { return -1; }

int BaseType::getTypeIndicator() { return typeIndicator; }
