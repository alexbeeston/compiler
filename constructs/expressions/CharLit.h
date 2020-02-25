//
// Created by abeeston on 2/20/20.
//

#ifndef COMPILERS_CHARLIT_H
#define COMPILERS_CHARLIT_H

#include "Expression.h"

struct CharLit : Expression
{
    char charLitValue;
    CharLit(char p_charLitValue);
    void print();
};
#endif //COMPILERS_CHARLIT_H
