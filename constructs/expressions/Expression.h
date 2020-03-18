//
// Created by abeeston on 2/20/20.
//

#ifndef COMPILERS_EXPRESSION_H
#define COMPILERS_EXPRESSION_H

#include <string>
#include "../../global.h"


struct Expression
{
    int value;
    int type;
    virtual void print();
    virtual Register emit();
};
#endif //COMPILERS_EXPRESSION_H
