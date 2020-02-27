//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_WRITE_H
#define COMPILERS_WRITE_H

#include "Statement.h"

struct Write:Statement
{
    Write();
    void print() override;
};
#endif //COMPILERS_WRITE_H
