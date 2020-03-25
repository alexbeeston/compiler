//
// Created by abeeston on 3/24/20.
//

#ifndef COMPILERS_LITERAL_H
#define COMPILERS_LITERAL_H

#include "Expression.h"

struct Literal:Expression
{
    int typeIndicator;
    int value;
    Literal(int);
    Literal(char);
//    Literal(bool);
//    Literal(std::string);
//    Literal(char);
    Register emit() override;
};
#endif //COMPILERS_LITERAL_H
