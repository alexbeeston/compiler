#include <iostream>

#include "Repeat.h"

Repeat::Repeat(Expression* p_expression, std::vector<Statement*>* p_statements)
{
    expression = p_expression;
    statements = p_statements;
}

void Repeat::print()
{
    std::cout << "repeat ";
    for (Statement* statement : *statements)
    {
        statement->print();
        std::cout << "; ";
    }
    std::cout << " until ";
    expression->print();
}