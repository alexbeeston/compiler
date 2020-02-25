#include <iostream>

#include "Function.h"

Function::Function(char* p_ident):Routine(p_ident)
{
}

void Function::print()
{
    std::cout << "FUNCTION " << ident << "();" << std::endl;
}