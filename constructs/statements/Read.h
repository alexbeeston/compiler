//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_READ_H
#define COMPILERS_READ_H

#include "Statement.h"

struct Read:Statement
{
    Read();
    void print() override;
};
#endif //COMPILERS_READ_H
