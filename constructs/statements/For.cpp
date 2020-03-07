#include <iostream>

#include "For.h"

For::For(Expression* p_left, int p_location, Expression* p_right, std::vector<Statement*>* p_statements)
{
    left = p_left;
    location = p_location;
    right = p_right;
    statements = p_statements;
}

void For::print()
{
    std::cout << "FOR";
    left->print();
    std::cout << " := ";
    if (location == 0) std::cout << "down to";
    else std::cout << "to";
    right->print();
    for (Statement* statement : *statements) statement->print();
}
