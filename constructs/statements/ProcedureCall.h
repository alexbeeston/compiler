//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_PROCEDURECALL_H
#define COMPILERS_PROCEDURECALL_H

#include <vector>

#include "Statement.h"
#include "../expressions/Expression.h"

struct ProcedureCall:Statement
{
    std::vector<Expression*>* expressions;
    ProcedureCall(std::vector<Expression*>*);
    void print() override;
};
#endif //COMPILERS_PROCEDURECALL_H
