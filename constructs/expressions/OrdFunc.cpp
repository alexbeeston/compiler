#include <iostream>

#include "OrdFunc.h"
#include "../../global.h"

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
    if (expression->getTypeIndicator() == CHAR)
    {
        expression->typeIndicator = INTEGER;
        return expression->emit();
    }
    else throw std::runtime_error("Error: Ord() attempted on a non-character.");
}

TypeIndicator OrdFunc::getTypeIndicator() { return INTEGER; }