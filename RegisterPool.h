//
// Created by abeeston on 3/17/20.
//

#ifndef COMPILERS_REGISTERPOOL_H
#define COMPILERS_REGISTERPOOL_H

#include <vector>

#include "Register.h"

struct RegisterPool
{
    std::vector<Register> registers;
    Register getRegister();
    void returnRegister(Register);
    RegisterPool();
};
#endif //COMPILERS_REGISTERPOOL_H
