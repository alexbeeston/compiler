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

int Expression::getValue() { return value; }


