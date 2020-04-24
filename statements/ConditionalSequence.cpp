#include <iostream>

#include "ConditionalSequence.h"

ConditionalSequence::ConditionalSequence(Expression* p_expression, std::vector<Statement*>* p_statements)
{
   expression = p_expression;
   statements = p_statements;
}

void ConditionalSequence::print()
{
    expression->print();
    std::cout << "\n";
    for (Statement* statement : *statements) statement->print();
}
