//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_WHILE_H
#define COMPILERS_WHILE_H

#include <vector>

#include "Statement.h"
#include "../expressions/Expression.h"

struct While:Statement
{
    Expression* expression;
    std::vector<Statement*>* statements;

    While(Expression*, std::vector<Statement*>*);
    void print() override;
};
#endif //COMPILERS_WHILE_H
