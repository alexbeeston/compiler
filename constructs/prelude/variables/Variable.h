//
// Created by abeeston on 3/14/20.
//

#ifndef COMPILERS_VARIABLE_H
#define COMPILERS_VARIABLE_H

#include <string>

#include "../../expressions/Expression.h"
#include "../types/BaseType.h"

struct Variable
{
    std::string ident;
    Expression expression;
    int offsetFromGlobal;
    BaseType type;
    Variable(std::string, Expression, int, BaseType);
    void print();
};
#endif //COMPILERS_VARIABLE_H
