#include <iostream>
#include <string>

#include "Expression.h"
#include "NumericLit.h"

NumericLit::NumericLit(int p_numericLitValue) : Expression ()
{
    type = 0;
    value = p_numericLitValue;
    numericLitValue = p_numericLitValue;
}

void NumericLit::print()
{
    std::cout << numericLitValue;
}

std::string NumericLit::emit()
{
    std::cout << "li   $t0   " << numericLitValue << "\n";
    return "$t0"; // assumes same temp register every time
}