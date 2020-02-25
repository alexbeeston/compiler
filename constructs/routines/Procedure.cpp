#include <iostream>

#include "Procedure.h"

Procedure::Procedure()
{
    std::cout << "procedure constructor" << std::endl;
}

void Procedure::print()
{
    std::cout << "Procedure print function" << std::endl;
}