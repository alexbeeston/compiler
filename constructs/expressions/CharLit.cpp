#include <iostream>

#include "Expression.h"
#include "CharLit.h"

CharLit::CharLit(char p_charLitValue):Expression()
{
    charLitValue = p_charLitValue;
}

void CharLit::print()
{
    std::cout << charLitValue;
}