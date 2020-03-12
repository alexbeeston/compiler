#include <iostream>

#include "Statement.h"

Statement::Statement() { }
void Statement::print()
{
    std::cout << "[base statement print]";
}

void Statement::emit()
{
    std::cout << "[base statement emit]";
}
