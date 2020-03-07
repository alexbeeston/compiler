#include <iostream>

#include "LValueIdent.h"

LValueIdent::LValueIdent(std::string* p_ident)
{
    ident = p_ident;
}

void LValueIdent::print()
{
    std::cout << "." << *ident;
}

