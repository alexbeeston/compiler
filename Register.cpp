#include "Register.h"

Register::Register(std::string p_name)
{
    name = p_name;
}

Register::Register() {}

std::string Register::getName()
{
    return name;
}