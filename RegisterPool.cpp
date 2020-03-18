#include "RegisterPool.h"
#include "Register.h"

RegisterPool::RegisterPool()
{
    int NUM_REGISTER = 30;
    for (int i = NUM_REGISTER; i >= 0; i--)
    {
        registers.push_back(Register(std::string("$t" + std::to_string(i))));
    }
}

Register RegisterPool::getRegister()
{
    Register temp = registers.back();
    registers.pop_back();
    return temp;
}

void RegisterPool::returnRegister(Register reg)
{
    registers.push_back(reg);
}