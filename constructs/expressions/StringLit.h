//
// Created by abeeston on 2/20/20.
//

#ifndef COMPILERS_STRINGLIT_H
#define COMPILERS_STRINGLIT_H

#include "Expression.h"

struct StringLit : Expression
{
    char* stringLitValue;
    StringLit(char* p_value);
    void print();
};
#endif //COMPILERS_STRINGLIT_H
