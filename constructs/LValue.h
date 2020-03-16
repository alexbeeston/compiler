//
// Created by abeeston on 3/3/20.
//

#ifndef COMPILERS_LVALUE_H
#define COMPILERS_LVALUE_H

#include <vector>
#include <string>

#include "LValueBase.h"

struct LValue
{
    std::vector<LValueBase*>* sequence;
    LValue(std::vector<LValueBase*>*);
    void print();
    std::string getKey();
};
#endif //COMPILERS_LVALUE_H
