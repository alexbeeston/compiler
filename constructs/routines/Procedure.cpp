#include <iostream>

#include "Procedure.h"

Procedure::Procedure(char* p_ident):Routine(p_ident)
{
}

void Procedure::print()
{
    std::cout << "PROCEDURE " << ident << "();" << std::endl;
}