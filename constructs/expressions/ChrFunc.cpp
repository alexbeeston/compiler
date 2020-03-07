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
