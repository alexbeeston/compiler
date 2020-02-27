//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_PROCEDURECALL_H
#define COMPILERS_PROCEDURECALL_H

#include "Statement.h"

struct ProcedureCall:Statement
{
    ProcedureCall();
    void print() override;
};
#endif //COMPILERS_PROCEDURECALL_H
