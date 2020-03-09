#include <iostream>
#include <string>

#include "For.h"

For::For(char* p_ident, Expression* p_left, int p_location, Expression* p_right, std::vector<Statement*>* p_statements)
{
    ident = new std::string(p_ident);
    left = p_left;
    location = p_location;
    right = p_right;
    statements = p_statements;
}

void For::print()
{
    std::cout << "FOR " << *ident << " = ";
    left->print();
    std::cout << " := ";
    if (location == 0) std::cout << "down to";
    else std::cout << "to";
    right->print();
    std::cout << "  ";
    for (Statement* statement : *statements)
    {
        statement->print();
        std::cout << "  ; ";
    }
}
