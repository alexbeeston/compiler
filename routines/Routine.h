//
// Created by abeeston on 2/24/20.
//

#ifndef COMPILERS_ROUTINE_H
#define COMPILERS_ROUTINE_H

#include <vector>

#include "ParameterSet.h"
#include "Body.h"

struct Routine
{
    std::string ident;
    std::vector<ParameterSet*>* formalParameters;
    Body* body;
    virtual void print();
    void printParameters();
    Routine(char*, std::vector<ParameterSet*>*, Body*);
    void emit();
    std::vector<int> offsets;
    void computeOffsets_internal(int);
    virtual void computeOffsets();
    int stackSize;
};
#endif //COMPILERS_ROUTINE_H
