//
// Created by abeeston on 3/24/20.
//

#ifndef COMPILERS_LITERAL_H
#define COMPILERS_LITERAL_H

#include "Expression.h"

struct Literal:Expression
{
    Literal();
    Literal(int);
    Literal(char);
    Literal(bool);
    Literal(char*);
    Register emit() override;
    bool isCTV() override;
};
#endif //COMPILERS_LITERAL_H
