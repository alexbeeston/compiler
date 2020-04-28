#include <iostream>

#include "ProcedureCall.h"
#include "../miscellaneous/utilities.h"

ProcedureCall::ProcedureCall(char* p_ident, std::vector<Expression*>* p_expressions)
{
    ident = new std::string(p_ident);
    expressions = p_expressions;
}

void ProcedureCall::print()
{
    std::cout << *ident << "(";
    for (Expression* express : *expressions)
    {
        express->print();
        std::cout << ", ";
    }
    std::cout << ");";
}

void ProcedureCall::emit()
{
    auto spilledRegisters = spillRegisters();
    restoreRegisters(spilledRegisters);
}