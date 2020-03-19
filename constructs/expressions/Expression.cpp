#include <iostream>
#include <string>

#include "Expression.h"

void Expression::print()
{
    std::cout << "[pretty print base expression]";
}

Register Expression::emit()
{
    std::cout << "Error: calling the base Expression emit function. Going to return Register().\n";
    return Register();
}

int Expression::getTypeIndicator() { return typeIndicator; } // if this gets called, your're in trouble; I want to leave this line of code the same so that the literal types can inherit it, but it should never be called on the base class. Not sure if marking it virtual will prohibit this function from being called in the base class though.


