//
// Created by abeeston on 3/9/20.
//

#ifndef COMPILERS_FUNCTIONCALL_H
#define COMPILERS_FUNCTIONCALL_H

#include <string>
#include <vector>

#include "Expression.h"

struct FunctionCall:Expression
{
    std::string* ident;
    std::vector<Expression*>* params;
    FunctionCall(char*, std::vector<Expression*>*);
    void print() override;
    Register emit() override;
    PrimitiveType resolvePrimitiveType() override;
    TypeStyle getTypeStyle() override;
};
#endif //COMPILERS_FUNCTIONCALL_H
