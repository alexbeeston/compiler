#include <iostream>

#include "LValueBase.h"

LValueBase::LValueBase()
{
    accessor = std::string("[LValue Base keyString]");
}

LValueBase::LValueBase(Expression* p_index)
{
    index = p_index;
}

LValueBase::LValueBase(char* p_accessor)
{
    accessor = std::string(p_accessor);
}

void LValueBase::print()
{
    std::cout << "[LValue Base]";
}
