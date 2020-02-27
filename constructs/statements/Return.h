//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_RETURN_H
#define COMPILERS_RETURN_H

#include "Statement.h"

struct Return:Statement
{
    Return();
    void print() override;
};
#endif //COMPILERS_RETURN_H
