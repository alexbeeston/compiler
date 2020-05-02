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

PrimitiveType Expression::resolvePrimitiveType() { return primitiveType; }

int Expression::getValue() { throw std::runtime_error("Calling Expression::getValue(). Should be called on a derived class.\n"); }

bool Expression::isCTV() { throw std::runtime_error("Expression::isCTV() - should be called on a derived class. This should be easy, since most derived classes inherit from BinaryOp."); }

TypeStyle Expression::getTypeStyle() { return SIMPLE; }
