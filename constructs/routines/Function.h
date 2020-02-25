//
// Created by abeeston on 2/24/20.
//

#ifndef COMPILERS_FUNCTION_H
#define COMPILERS_FUNCTION_H

#include "Routine.h"
#include "Body.h"
#include "../prelude/types/BaseType.h"

struct Function:Routine
{
    BaseType* type;
    Function(char*, std::vector<ParameterSet*>*, Body*, BaseType*);
    void print();
};
#endif //COMPILERS_FUNCTION_H
