//
// Created by abeeston on 2/20/20.
//

#ifndef COMPILERS_EXPRESSION_H
#define COMPILERS_EXPRESSION_H

#include <string>
#include "../../Register.h"

struct Expression
{
    int value;
    int typeIndicator;
    virtual int getValue();
    virtual void print();
    virtual Register emit();
    virtual int getTypeIndicator();
};
#endif //COMPILERS_EXPRESSION_H
