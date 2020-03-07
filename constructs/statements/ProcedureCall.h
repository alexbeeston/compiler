//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_PROCEDURECALL_H
#define COMPILERS_PROCEDURECALL_H

#include <vector>
#include <string>

#include "Statement.h"
#include "../expressions/Expression.h"

struct ProcedureCall:Statement
{
    std::string* ident;
    std::vector<Expression*>* expressions;
    ProcedureCall(char*, std::vector<Expression*>*);
    void print() override;
};
#endif //COMPILERS_PROCEDURECALL_H
