//
// Created by abeeston on 2/20/20.
//

#ifndef COMPILERS_EXPRESSION_H
#define COMPILERS_EXPRESSION_H

#include <string>
#include <stdexcept>
#include "../registerPool/Register.h"
#include "../Enums.h"

struct Expression
{
    int value;
    virtual bool isCTV();
    TypeIndicator typeIndicator;
    virtual int getValue();
    virtual void print();
    virtual Register emit();
    virtual TypeIndicator getTypeIndicator();
    virtual Style getStyle();
};
#endif //COMPILERS_EXPRESSION_H
