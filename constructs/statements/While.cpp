#include <iostream>

#include "While.h"

While::While(Expression* p_expression, std::vector<Statement*>* p_statements)
{
    expression = p_expression;
    statements = p_statements;
}

void While::print()
{
    std::cout << "while ";
    expression->print();
    std::cout << " do ";
    for (Statement* statement : *statements)
    {
        statement->print();
        std::cout << "; ";
    }
}