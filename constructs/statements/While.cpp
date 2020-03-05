#include <iostream>

#include "While.h"

While::While(Expression* p_expression, std::vector<Statement*>* p_statements)
{
    expression = p_expression;
    statements = p_statements;
}

void While::print()
{
    std::cout << "While Statement: Expression - ";
    expression->print();
    std::cout << " Statements - ";
    for (Statement* statement : *statements) statement->print();
}