//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_STOP_H
#define COMPILERS_STOP_H

#include "Statement.h"

struct Stop:Statement
{
    Stop();
    void print() override;
    void emit() override;
};
#endif //COMPILERS_STOP_H
