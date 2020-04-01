#include "RegisterPool.h"
#include "Register.h"

RegisterPool::RegisterPool()
{
    int NUM_REGISTER = 30;
    for (int i = NUM_REGISTER; i >= 0; i--) registers.push(Register(std::string("$t" + std::to_string(i))));
}

Register RegisterPool::getRegister()
{
    Register temp = registers.top();
    registers.pop();
    return temp;
}

Register RegisterPool::getGlobalPointer()
{
    return Register(std::string("$gp"));
}

void RegisterPool::returnRegister(Register reg)
{
    registers.push(reg);
}