#include <iostream>

#include "Routine.h"

Routine::Routine(char* p_ident)
{
    ident = p_ident;
}

void Routine::print()
{
    std::cout << "This should be overriden" << std::endl;
}