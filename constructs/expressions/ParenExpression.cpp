#include <iostream>

#include "ParenExpression.h"

ParenExpression::ParenExpression(Expression* p_expression)
{
    expression = p_expression;
}

void ParenExpression::print()
{
    std::cout << " ( ";
    expression->print();
    std::cout << " ) ";
}

Register ParenExpression::emit()
{
    return expression->emit();
}
