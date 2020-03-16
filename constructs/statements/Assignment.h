//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_ASSIGNMENT_H
#define COMPILERS_ASSIGNMENT_H

#include "Statement.h"
#include "../LValue.h"
#include "../expressions/Expression.h"

struct Assignment:Statement
{
    Expression* expression;
    LValue* lValue;
    Assignment(LValue*, Expression*);
    void print() override;
    void emit() override;
};
#endif //COMPILERS_ASSIGNMENT_H
