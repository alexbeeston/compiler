#include <iostream>

#include "SimpleType.h"

SimpleType::SimpleType(std::string* p_ident)
{
    ident = p_ident;
    size = 4;
}

void SimpleType::print()
{
    std::cout << *ident;
}
