#include <iostream>

#include "Routine.h"

Routine::Routine()
{
    int dog = 10;
}

void Routine::print()
{
    std::cout << "This should be overriden" << std::endl;
}