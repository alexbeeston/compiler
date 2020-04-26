#include "RegisterPool.h"
#include "Register.h"

RegisterPool::RegisterPool()
{
    int NUM_TEMP_REGISTERS = 10;
    int NUM_SAVED_REGISTERS = 8;
    addRegisterClass(NUM_SAVED_REGISTERS, "s");
    addRegisterClass(NUM_TEMP_REGISTERS, "t");
}

void RegisterPool::addRegisterClass(int quantity, std::string type)
{
    for (int i = quantity - 1; i >= 0; i--) availableRegisters.push(Register(std::string("$" + type + std::to_string(i))));
}

Register RegisterPool::getRegister()
{
    if (!availableRegisters.empty())
    {
        Register temp = availableRegisters.top();
        availableRegisters.pop();
        registersInUse.push_back(temp);
        return temp;
    }
    else throw std::runtime_error("Out of availableRegisters");
}

Register RegisterPool::getGlobalPointer()
{
    return Register(std::string("$gp"));
}

void RegisterPool::returnRegister(Register reg)
{
    if (reg.getName() != "$gp" && reg.getName() != "$fp" && reg.getName() != "$sp")
    {
        int i = 0;
        while (registersInUse[i].getName() != reg.getName())
        {
            if (i != registersInUse.size() - 1) ++i;
            else throw std::runtime_error("RegisterPool::returnRegister - attempting to return a register but can't find it in the list of registersInUse");
        }
        registersInUse.erase(registersInUse.begin() + i);
        availableRegisters.push(reg);
    }
}