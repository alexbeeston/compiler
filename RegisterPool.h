//
// Created by abeeston on 3/17/20.
//

#ifndef COMPILERS_REGISTERPOOL_H
#define COMPILERS_REGISTERPOOL_H

#include <stack>

#include "Register.h"

struct RegisterPool
{
    std::stack <Register> registers;
    Register getRegister();
    Register getGlobalPointer();
    void returnRegister(Register);
    RegisterPool();
};
#endif //COMPILERS_REGISTERPOOL_H
