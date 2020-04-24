//
// Created by abeeston on 3/17/20.
//

#ifndef COMPILERS_REGISTERPOOL_H
#define COMPILERS_REGISTERPOOL_H

#include <stack>
#include <stdexcept>

#include "Register.h"

struct RegisterPool
{
    std::stack <Register> registers;
    Register getRegister();
    Register getGlobalPointer();
    void returnRegister(Register);
    RegisterPool();
    void addRegisterClass(int, std::string);
};
#endif //COMPILERS_REGISTERPOOL_H
