#include <iostream>

#include "OrdFunc.h"

OrdFunc::OrdFunc(Expression* p_expression)
{
    expression = p_expression;
}

void OrdFunc::print()
{
    std::cout << "ord(";
    expression->print();
    std::cout << ")";
}