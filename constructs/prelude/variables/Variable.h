//
// Created by abeeston on 3/14/20.
//

#ifndef COMPILERS_VARIABLE_H
#define COMPILERS_VARIABLE_H

#include <string>

#include "../LookUpItem.h"

struct Variable:LookUpItem
{
    int offset; // set by the symbol table;
    std::string baseRegister;
    Variable();
    Variable(std::string, BaseType);
    void print() override;
};
#endif //COMPILERS_VARIABLE_H
