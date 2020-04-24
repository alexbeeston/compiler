#include <iostream>

#include "PredFunc.h"

PredFunc::PredFunc(Expression* p_expression)
{
    expression = p_expression;
}

void PredFunc::print()
{
    std::cout << "pred(";
    expression->print();
    std::cout << ")";
}