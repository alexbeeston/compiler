//
// Created by abeeston on 2/24/20.
//

#ifndef COMPILERS_METHOD_H_
#define COMPILERS_METHOD_H_
#include <vector>

#include "ParameterSet.h"
#include "Body.h"
#include "../types/BaseType.h"

struct Method
{
    std::string ident;
    std::vector<ParameterSet*>* formalParameters;
    Body* body;
    virtual void print();
    void printParameters();
    Method(char*, std::vector<ParameterSet*>*, BaseType*, Body*);
    void emit();
    std::vector<int> offsets;
    virtual void computeOffsets();
    int sizeOfParametersAndReturnType;
    bool isForwardDeclared;
    BaseType* type_temp;
};
#endif //COMPILERS_METHOD_H_
