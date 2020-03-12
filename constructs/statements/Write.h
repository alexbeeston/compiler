//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_WRITE_H
#define COMPILERS_WRITE_H

#include <vector>

#include "Statement.h"
#include "../expressions/Expression.h"

struct Write:Statement
{
    std::vector<Expression*>* expressions;
    Write(Expression*, std::vector<Expression*>*);
    void emit() override;
    void print() override;
};
#endif //COMPILERS_WRITE_H
