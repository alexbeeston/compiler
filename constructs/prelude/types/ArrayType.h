//
// Created by abeeston on 3/3/20.
//

#ifndef COMPILERS_ARRAYTYPE_H
#define COMPILERS_ARRAYTYPE_H

#include "BaseType.h"
#include "../../expressions/Expression.h"

struct ArrayType:BaseType
{
    Expression* low;
    Expression* high;
    BaseType* type;
    ArrayType(Expression*, Expression*, BaseType*);
    void print() override;
};
#endif //COMPILERS_ARRAYTYPE_H
