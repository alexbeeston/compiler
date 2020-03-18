//
// Created by abeeston on 2/20/20.
//

#ifndef COMPILERS_EXPRESSION_H
#define COMPILERS_EXPRESSION_H

#include <string>

struct Expression
{
    int value;
    int type;
    virtual void print();
    virtual std::string emit();
};
#endif //COMPILERS_EXPRESSION_H
