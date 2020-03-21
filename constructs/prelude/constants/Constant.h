//
// Created by abeeston on 2/20/20.
//

#ifndef COMPILERS_CONSTANT_H
#define COMPILERS_CONSTANT_H

#include <string>

#include "../../expressions/Expression.h"

struct Constant
{
    Expression* value;
    std::string ident;
    Constant();
    Constant(char*, Expression*);
    void print();
};
#endif //COMPILERS_CONSTANT_H
