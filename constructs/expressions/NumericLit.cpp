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

Register NumericLit::emit()
{
    Register r = rp.getRegister();
    std::cout << "li " << r.name << " " << numericLitValue << "\n";
    return r; // assumes same temp register every time
}