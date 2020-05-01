//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_RETURN_H
#define COMPILERS_RETURN_H

#include "Statement.h"
#include "../expressions/Expression.h"

struct Return:Statement
{
    Expression* expression;
    Return();
    Return(Expression*);
    void print() override;
    void emit() override;
};
#endif //COMPILERS_RETURN_H
