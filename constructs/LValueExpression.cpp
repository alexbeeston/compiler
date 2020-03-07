#include <iostream>

#include "LValueExpression.h"

LValueExpression::LValueExpression(Expression* p_expression)
{
    expression = p_expression;
}

void LValueExpression::print()
{
    std::cout << "[";
    expression->print();
    std::cout << "]";
}
