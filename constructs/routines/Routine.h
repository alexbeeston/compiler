//
// Created by abeeston on 2/24/20.
//

#ifndef COMPILERS_ROUTINE_H
#define COMPILERS_ROUTINE_H

#include <vector>

#include "ParameterSet.h"

struct Routine
{
    char* ident;
    std::vector<ParameterSet*>* formalParameters;
    virtual void print();
    void printParameters();
    Routine(char*, std::vector<ParameterSet*>*);
};
#endif //COMPILERS_ROUTINE_H
