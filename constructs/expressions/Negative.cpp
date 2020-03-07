#include <iostream>

#include "Negative.h"

Negative::Negative(Expression* p_originalExpression)
{
    originalExpression = p_originalExpression;
}

void Negative::print()
{
    std::cout << " - ";
    originalExpression->print();
}
