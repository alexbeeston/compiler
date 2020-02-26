//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_IF_H
#define COMPILERS_IF_H

#include <vector>

#include "Statement.h"

struct If:Statement
{
    If();
    void print() override;
};
#endif //COMPILERS_IF_H
