#include <iostream>

#include "SimpleType.h"

SimpleType::SimpleType(std::string* p_ident)
{
    ident = p_ident;
}

void SimpleType::print()
{
    std::cout << "simple type: ident - " << *ident;
}
