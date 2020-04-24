//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_READ_H
#define COMPILERS_READ_H

#include <vector>

#include "Statement.h"
#include "../miscellaneous/LValue.h"

struct Read:Statement
{
    std::vector<LValue*>* lValues;
    Read(LValue*, std::vector<LValue*>*);
    void print() override;
    void emit() override;
};
#endif //COMPILERS_READ_H
