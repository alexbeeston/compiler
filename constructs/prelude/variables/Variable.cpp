#include <iostream>

#include "Variable.h"

Variable::Variable(std::string p_ident, Expression p_expression, int p_offset, BaseType p_type)
{
    ident = p_ident;
    expression = p_expression;
    offsetFromGlobal = p_offset;
    type = p_type;
}

void Variable::print()
{
    std::cout << ident << " : ";
    type.print();
}