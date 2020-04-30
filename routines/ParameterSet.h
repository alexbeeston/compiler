//
// Created by abeeston on 2/25/20.
//

#ifndef COMPILERS_PARAMETERSET_H
#define COMPILERS_PARAMETERSET_H

#include <vector>
#include "../types/BaseType.h"

struct ParameterSet
{
    int passBy;
    std::vector<std::string> identList;
    BaseType* type;
    ParameterSet(int, std::vector<char*>*, BaseType*);
    void print();
};
#endif //COMPILERS_PARAMETERSET_H
