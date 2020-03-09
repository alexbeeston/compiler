//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_FOR_H
#define COMPILERS_FOR_H

#include <vector>
#include <string>

#include "Statement.h"
#include "../expressions/Expression.h"

struct For:Statement
{
    std::string* ident;
    Expression* left;
    int location;
    Expression* right;
    std::vector<Statement*>* statements;
    For(char*, Expression*, int, Expression*, std::vector<Statement*>*);
    void print() override;
};
#endif //COMPILERS_FOR_H
