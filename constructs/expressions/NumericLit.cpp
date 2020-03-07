#include <iostream>
#include <string>

#include "Expression.h"
#include "NumericLit.h"

NumericLit::NumericLit(int p_numericLitValue) : Expression ()
{
    numericLitValue = p_numericLitValue;
    contents = NUMBER;
}

void NumericLit::print()
{
    std::cout << numericLitValue;
}