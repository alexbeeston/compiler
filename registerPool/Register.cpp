#include "Register.h"

Register::Register(std::string p_name)
{
    name = p_name;
    space = -1;
    containsAddress = false;
}

Register::Register() {}

std::string Register::getName()
{
    return name;
}