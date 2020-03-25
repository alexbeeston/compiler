//
// Created by abeeston on 3/21/20.
//

#ifndef COMPILERS_BOOLEANLIT_H
#define COMPILERS_BOOLEANLIT_H

#include "Expression.h"

struct BooleanLit:Expression
{
   BooleanLit(int);
   Register emit() override;
};
#endif //COMPILERS_BOOLEANLIT_H
