#include <iostream>

#include "Expression.h"
#include "CharLit.h"

CharLit::CharLit(char p_charLitValue):Expression()
{
    type = 1;
    value = p_charLitValue;
    charLitValue = p_charLitValue;
}

void CharLit::print()
{
    std::cout << charLitValue;
}

std::string CharLit::emit()
{
    std::cout << "li $t0 '" << (char)value << "' # load a character\n";
    return "$t0";
}