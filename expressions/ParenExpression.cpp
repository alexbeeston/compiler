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

int ParenExpression::getValue()
{
    if (!expression->isCTV()) throw std::runtime_error("ParenExpression::getValue() - Operand is not CTV");
    return expression->getValue();
}

PrimitiveType ParenExpression::getPrimitiveType() { return expression->getPrimitiveType(); }
