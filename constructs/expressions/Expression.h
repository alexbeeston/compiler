//
// Created by abeeston on 2/20/20.
//

#ifndef COMPILERS_EXPRESSION_H
#define COMPILERS_EXPRESSION_H

#include <string>
#include "../../Register.h"
#include "../../Enums.h"

struct Expression
{
    int value;
    TypeIndicator typeIndicator;
    virtual int getValue();
    virtual void print();
    virtual Register emit();
    virtual TypeIndicator getTypeIndicator();
};
#endif //COMPILERS_EXPRESSION_H
