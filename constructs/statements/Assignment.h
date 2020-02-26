//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_ASSIGNMENT_H
#define COMPILERS_ASSIGNMENT_H

#include "Statement.h"

struct Assignment:Statement
{
    Assignment();
    void print() override;
};
#endif //COMPILERS_ASSIGNMENT_H
