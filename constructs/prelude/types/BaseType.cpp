#include <iostream>

#include "BaseType.h"


BaseType::BaseType()
{
    int test = 1234;
}

void BaseType::print()
{
    std::cout << "This is a base type. It should be over-written.";
}
