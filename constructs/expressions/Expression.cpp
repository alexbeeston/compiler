#include <iostream>
#include <string>

#include "Expression.h"

void Expression::print()
{
    std::cout << "[pretty print base expression]";
}

void Expression::emitLabel()
{
    std::cout << "[emit base expression]\n";
}

std::string Expression::emit()
{
   return "[a register]" ;
}


