#include <iostream>
#include <string>
#include "../../global.h"
#include "NumericLit.h"

NumericLit::NumericLit(int p_numericLitValue) : Expression ()
{
    typeIndicator = 0;
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
    return r;
}