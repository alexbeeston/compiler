#include <iostream>

#include "OrdFunc.h"
#include "../global.h"

OrdFunc::OrdFunc(Expression* p_expression)
{
    expression = p_expression;
    primitiveType = INTEGER;
}

void OrdFunc::print()
{
    std::cout << "ord(";
    expression->print();
    std::cout << ")";
}

Register OrdFunc::emit()
{
    if (expression->resolvePrimitiveType() != CHAR) throw std::runtime_error("Error: Ord() attempted on a non-character.");
    expression->primitiveType = INTEGER;
    Register reg = expression->emit();
    reg.containsAddress = false;
    return reg;
}

PrimitiveType OrdFunc::resolvePrimitiveType() { return INTEGER; }