//
// Created by abeeston on 2/24/20.
//

#ifndef COMPILERS_PROCEDURE_H
#define COMPILERS_PROCEDURE_H

#include "Routine.h"

struct Procedure:Routine
{
    Procedure(char*);
    void print();
};
#endif //COMPILERS_PROCEDURE_H
