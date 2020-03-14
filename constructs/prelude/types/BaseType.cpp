#include <iostream>

#include "BaseType.h"


BaseType::BaseType()
{
    size = 4;
}

void BaseType::print()
{
    std::cout << "[base type]";
}
