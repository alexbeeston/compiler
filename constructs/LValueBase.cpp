#include <iostream>

#include "LValueBase.h"

LValueBase::LValueBase()
{
    ident = std::string("[LValue Base keyString]");
}

LValueBase::LValueBase(Expression* p_index)
{
    indexer = p_index;
}

LValueBase::LValueBase(char* p_accessor)
{
    ident = std::string(p_accessor);
}

void LValueBase::print()
{
    std::cout << "[LValue Base]";
}
