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
    int offset;
    std::string baseRegister;
    BaseType type;
    Variable();
    Variable(std::string, Expression, BaseType);
    void print();
};
#endif //COMPILERS_VARIABLE_H
