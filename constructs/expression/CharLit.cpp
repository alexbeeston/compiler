#include <iostream>
#include "Expression.h"
#include "CharLit.h"

CharLit::CharLit(char p_charLitValue):Expression(new char(p_charLitValue)) {
    charLitValue = p_charLitValue;
}

