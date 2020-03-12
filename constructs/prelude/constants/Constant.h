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
    std::string* identifier;
    Constant(char* p_identifier, Expression* p_value);
    void print();
};
#endif //COMPILERS_CONSTANT_H
