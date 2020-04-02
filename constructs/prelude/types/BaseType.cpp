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
    std::cout << "# BaseType::computeSize()\n";
    return -1;
}

TypeIndicator BaseType::getTypeIndicator() { return typeIndicator; }

LValueType BaseType::getLValueType() { return lValueType; }
