//
// Created by abeeston on 2/24/20.
//

#ifndef COMPILERS_ROUTINE_H
#define COMPILERS_ROUTINE_H

#include <vector>

#include "ParameterSet.h"
#include "Body.h"
#include "../types/BaseType.h"

struct Routine
{
    std::string ident;
    std::vector<ParameterSet*>* formalParameters;
    Body* body;
    virtual void print();
    void printParameters();
    Routine(char*, std::vector<ParameterSet*>*, BaseType*, Body*);
    void emit();
    std::vector<int> offsets;
    void computeOffsets_internal(int);
    virtual void computeOffsets();
    int sizeOfParametersAndReturnType;
    bool isForwardDeclared;
    BaseType* type_temp;
};
#endif //COMPILERS_ROUTINE_H
