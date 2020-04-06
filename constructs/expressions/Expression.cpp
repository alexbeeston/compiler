#include <iostream>
#include <string>

#include "Expression.h"

void Expression::print()
{
    std::cout << "[pretty print base expression]";
}

Register Expression::emit()
{
    throw std::runtime_error("Constructing the base Expression struct");
}

TypeIndicator Expression::getTypeIndicator() { return typeIndicator; }

int Expression::getValue()
{
    throw std::runtime_error("Calling Expression::getValue(). Should be calling on a derived type.\n");
}

bool Expression::isCTV() { return false; }

Style Expression::getStyle() { return PRIMITIVE_TYPE; }
