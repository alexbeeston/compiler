#include <iostream>

#include "OrdFunc.h"
#include "../global.h"

OrdFunc::OrdFunc(Expression* p_expression)
{
    expression = p_expression;
}

void OrdFunc::print()
{
    std::cout << "ord(";
    expression->print();
    std::cout << ")";
}

Register OrdFunc::emit()
{
    if (expression->getPrimitiveType() != CHAR) throw std::runtime_error("Error: Ord() attempted on a non-character.");
    expression->typeIndicator = INTEGER;
    Register reg = expression->emit();
    reg.containsAddress = false;
    return reg;
}

PrimitiveType OrdFunc::getPrimitiveType() { return INTEGER; }