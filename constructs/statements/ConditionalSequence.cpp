#include <iostream>

#include "ConditionalSequence.h"

ConditionalSequence::ConditionalSequence(Expression* p_expression, std::vector<Statement*>* p_statements)
{
   expression = p_expression;
   statements = p_statements;
}

void ConditionalSequence::print()
{
    std::cout << "[conditional sequence] ";
}
