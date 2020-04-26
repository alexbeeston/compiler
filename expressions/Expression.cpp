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

PrimitiveType Expression::getPrimitiveType() { return typeIndicator; }

int Expression::getValue()
{
    throw std::runtime_error("Calling Expression::getValue(). Should be calling on a derived type.\n");
}

bool Expression::isCTV() { return false; }

TypeStyle Expression::getStyle() { return SIMPLE; }
