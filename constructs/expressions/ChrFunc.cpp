#include <iostream>

#include "ChrFunc.h"

ChrFunc::ChrFunc(Expression* p_expression)
{
    expression = p_expression;
}

void ChrFunc::print()
{
    std::cout << "chr(";
    expression->print();
    std::cout << ")";
}

Register ChrFunc::emit()
{
    if (expression->getTypeIndicator() == 0)
    {
        expression->typeIndicator = 1;
        return expression->emit();
    }
    else throw std::runtime_error("Error: chr() was called on a something other an an integer\n");
}

int ChrFunc::getTypeIndicator()
{
    return 1;
}
