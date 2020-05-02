//
// Created by abeeston on 4/25/20.
//

#ifndef COMPILER_UTILITIES_H
#define COMPILER_UTILITIES_H

#include <map>
#include <vector>
#include "../registerPool/Register.h"
#include "../expressions/Expression.h"

void copyContinuousMemory(int, int, int, Register, Register);
void dereferencePointer(Register);
std::map<std::string, int> spillRegisters();
void restoreSpilledRegisters(std::map<std::string, int> registers);
void addParametersToStack(std::string, std::vector<Expression*>, int);
void moveStackPointerUp(int);
void moveStackPointerDown(int);

#endif //COMPILER_UTILITIES_H
