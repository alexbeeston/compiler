#include <iostream>

#include "StringLit.h"

StringLit::StringLit(char* p_value):Expression(p_value) {
    stringLitValue = p_value;
}

void StringLit::print()
{
    std::cout << stringLitValue;
}

