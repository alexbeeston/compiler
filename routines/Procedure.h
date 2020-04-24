//
// Created by abeeston on 2/24/20.
//

#ifndef COMPILERS_PROCEDURE_H
#define COMPILERS_PROCEDURE_H

#include "Routine.h"
#include "Body.h"

struct Procedure:Routine
{
    Procedure(char*, std::vector<ParameterSet*>*, Body*);
    void print();
};
#endif //COMPILERS_PROCEDURE_H
