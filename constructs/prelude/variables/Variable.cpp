#include <iostream>

#include "Variable.h"

Variable::Variable() {}

Variable::Variable(std::string p_ident, Expression p_expression, BaseType p_type)
{
    ident = p_ident;
    expression = p_expression;
    type = p_type;
}

void Variable::print()
{
    std::cout << ident << " : ";
    type.print();
}