//
// Created by abeeston on 3/3/20.
//

#ifndef COMPILERS_CONDITIONALSEQUENCE_H
#define COMPILERS_CONDITIONALSEQUENCE_H

#include <vector>

#include "../expressions/Expression.h"
#include "Statement.h"

struct ConditionalSequence
{
    Expression* expression;
    std::vector<Statement*>* statements;
    ConditionalSequence(Expression*, std::vector<Statement*>*);
    void print();
};
#endif //COMPILERS_CONDITIONALSEQUENCE_H
