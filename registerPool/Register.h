//
// Created by abeeston on 3/17/20.
//

#ifndef COMPILERS_REGISTER_H
#define COMPILERS_REGISTER_H

#include <string>

struct Register
{
    std::string name;
    Register(std::string);
    Register();
    std::string getName();
    bool containsAddress;
    int space;
};
#endif //COMPILERS_REGISTER_H
