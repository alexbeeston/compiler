#include <iostream>

#include "Variable.h"

Variable::Variable() {}

Variable::Variable(std::string p_ident, BaseType p_type)
{
    ident = p_ident;
    type = p_type;
    baseRegister = "$gp";
}

void Variable::print()
{
    std::cout << ident << " : ";
    type.print();
}