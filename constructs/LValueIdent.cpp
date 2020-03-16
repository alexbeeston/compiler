#include <iostream>
#include <string>

#include "LValueIdent.h"

LValueIdent::LValueIdent(char* p_ident)
{
    ident = new std::string(p_ident);
    keyString = *ident;
}

void LValueIdent::print()
{
    std::cout << "." << *ident;
}

