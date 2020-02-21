#include "Expression.h"
#include "CharLit.h"

CharLit::CharLit(char p_value):Expression(&p_value) {
    charLitValue = p_value;
}

