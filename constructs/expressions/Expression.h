//
// Created by abeeston on 2/20/20.
//

#ifndef COMPILERS_EXPRESSION_H
#define COMPILERS_EXPRESSION_H

#include <string>

struct Expression
{
    virtual void print();
    virtual void emitLabel();
    virtual std::string emit();
};
#endif //COMPILERS_EXPRESSION_H
