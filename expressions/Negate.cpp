#include <iostream>

#include "Negate.h"

Negate::Negate(Expression* p_expression)
{
    expression = p_expression;
    primitiveType = INTEGER;
}

void Negate::print()
{
    std::cout << " ~";
    expression->print();
}

int Negate::getValue()
{
    throw std::runtime_error("Haven't yet implemented Negate::getValue() ");
}
