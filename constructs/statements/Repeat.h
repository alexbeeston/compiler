//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_REPEAT_H
#define COMPILERS_REPEAT_H

#include <vector>

#include "Statement.h"
#include "../expressions/Expression.h"
struct Repeat:Statement
{
    Expression* expression;
    std::vector<Statement*>* statements;
    Repeat(Expression*, std::vector<Statement*>*);
    void print() override;
    void emit() override;
};
#endif //COMPILERS_REPEAT_H
