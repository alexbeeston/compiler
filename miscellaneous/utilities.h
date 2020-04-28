//
// Created by abeeston on 4/25/20.
//

#ifndef COMPILER_UTILITIES_H
#define COMPILER_UTILITIES_H

#include <map>
#include "../registerPool/Register.h"

void copyContinuousMemory(int, int, int, Register, Register);
std::map<std::string, int> spillRegisters();
void restoreRegisters(std::map<std::string, int>);

#endif //COMPILER_UTILITIES_H
