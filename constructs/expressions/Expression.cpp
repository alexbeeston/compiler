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


