#include <iostream>

#include "Negate.h"

Negate::Negate(Expression* p_expression)
{
    expression = p_expression;
}

void Negate::print()
{
    std::cout << " ~";
    expression->print();
}
