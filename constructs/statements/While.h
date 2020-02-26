//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_WHILE_H
#define COMPILERS_WHILE_H

#include "Statement.h"

struct While:Statement
{
    While();
    void print() override;
};
#endif //COMPILERS_WHILE_H
