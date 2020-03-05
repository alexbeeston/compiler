#include <iostream>

#include "ProcedureCall.h"

ProcedureCall::ProcedureCall(std::vector<Expression*>* p_expressions)
{
    expressions = p_expressions;
}

void ProcedureCall::print()
{
    std::cout << "Procedure Call Statement: ";
    for (Expression* express : *expressions) express->print();
}