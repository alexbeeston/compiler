#include <iostream>

#include "ChrFunc.h"

ChrFunc::ChrFunc(Expression* p_expression)
{
    expression = p_expression;
    primitiveType = CHAR;
}

void ChrFunc::print()
{
    std::cout << "chr(";
    expression->print();
    std::cout << ")";
}

Register ChrFunc::emit()
{
    // validate
    if (expression->resolvePrimitiveType() != INTEGER) throw std::runtime_error("Error: chr() was called on something other than an integer. Sorry, can't print what it was without a lot of annoying if statements, at least as far as I know.");

    // continue
    expression->primitiveType = CHAR;
    Register reg = expression->emit();
    reg.containsAddress = false;
    return reg;
}
