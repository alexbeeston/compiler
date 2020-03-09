#include <iostream>

#include "LValueWithExpression.h"

LValueWithExpression::LValueWithExpression(Expression* p_expression)
{
    expression = p_expression;
}

void LValueWithExpression::print()
{
    std::cout << "[";
    expression->print();
    std::cout << "]";
}
