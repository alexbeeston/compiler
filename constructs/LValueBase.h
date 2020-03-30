//
// Created by abeeston on 3/7/20.
//

#ifndef COMPILERS_unique_guard_for_LValueBase
#define COMPILERS_unique_guard_for_LValueBase

#include "../constructs/expressions/Expression.h"

struct LValueBase
{
    LValueBase();
    LValueBase(Expression*);
    LValueBase(char*);
    virtual void print();
    std::string accessor;
    Expression* index;
};
#endif //COMPILERS_unique_guard_for_LValueBase
