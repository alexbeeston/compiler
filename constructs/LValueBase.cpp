#include <iostream>

#include "LValueBase.h"

LValueBase::LValueBase()
{
    keyString = std::string("[LValue Base keyString]");
}

void LValueBase::print()
{
    std::cout << "[LValue Base]";
}
