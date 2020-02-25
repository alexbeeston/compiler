#include <iostream>

#include "StringLit.h"

StringLit::StringLit(char* p_value):Expression() {
    stringLitValue = p_value;
}

void StringLit::print()
{
    std::cout << stringLitValue;
}

