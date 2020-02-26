//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_FOR_H
#define COMPILERS_FOR_H

#include "Statement.h"

struct For:Statement
{
    For();
    void print() override;
};
#endif //COMPILERS_FOR_H
