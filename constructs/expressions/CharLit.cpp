#include <iostream>
#include "../../global.h"
#include "Expression.h"
#include "CharLit.h"

CharLit::CharLit(char p_charLitValue):Expression()
{
    typeIndicator = 1;
    value = p_charLitValue;
    charLitValue = p_charLitValue;
}

void CharLit::print()
{
    std::cout << charLitValue;
}

Register CharLit::emit()
{
    Register r = rp.getRegister();
    std::cout << "li " << r.name << " " << (char)value << "' # load a character\n";
    return r;
}