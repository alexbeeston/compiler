#include "Register.h"

Register::Register(std::string p_name)
{
    name = p_name;
    space = -1;
}

Register::Register() {}

std::string Register::getName()
{
    return name;
}