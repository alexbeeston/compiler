//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_NULLSTATEMENT_H
#define COMPILERS_NULLSTATEMENT_H

#include "Statement.h"

struct NullStatement:Statement
{
    NullStatement();
    void print() override;
};
#endif //COMPILERS_NULLSTATEMENT_H
