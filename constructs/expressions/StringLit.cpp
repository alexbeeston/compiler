#include <iostream>
#include <string>

#include "StringLit.h"

StringLit::StringLit(char* p_value):Expression()
{
    stringLitValue = std::string(p_value);
}

void StringLit::print()
{
    std::cout << stringLitValue;
}

