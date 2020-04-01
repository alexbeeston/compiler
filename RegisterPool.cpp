#include "RegisterPool.h"
#include "Register.h"
#include <iostream>

RegisterPool::RegisterPool()
{
    int NUM_TEMP_REGISTERS = 10;
    int NUM_SAVED_REGISTERS = 8;
    addRegisterClass(NUM_SAVED_REGISTERS, "s");
    addRegisterClass(NUM_TEMP_REGISTERS, "t");
}

void RegisterPool::addRegisterClass(int quantity, std::string type)
{
    for (int i = quantity - 1; i >= 0; i--) registers.push(Register(std::string("$" + type + std::to_string(i))));
}

Register RegisterPool::getRegister()
{
    if (!registers.empty())
    {
        Register temp = registers.top();
        registers.pop();
        return temp;
    }
    else throw std::runtime_error("Out of registers");
}

Register RegisterPool::getGlobalPointer()
{
    return Register(std::string("$gp"));
}

void RegisterPool::returnRegister(Register reg)
{
    registers.push(reg);
}