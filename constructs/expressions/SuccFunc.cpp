#include <iostream>

#include "SuccFunc.h"

SuccFunc::SuccFunc(Expression* p_expression)
{
    expression = p_expression;
}

void SuccFunc::print()
{
    std::cout << "succ(";
    expression->print();
    std::cout << ")";
}
