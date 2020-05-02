#include <iostream>

#include "ProcedureCall.h"
#include "../miscellaneous/utilities.h"
#include "../types/BaseType.h"
#include "../global.h"

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
    // validate
    auto routine = st.retrieveRoutine(*ident);
    if (routine->type_temp != nullptr) throw std::runtime_error("ProcedureCall::emit() - the procedure has a non-nullptr return type");

    // continue
    auto spilledRegisters = spillRegisters();
    addParametersToStack(*ident, *expressions);
    std::cout << "# Call the procedure\n";
    std::cout << "jal " << *ident << "\n\n";
    std::cout << "# Deallocate Parameters\n";
    moveStackPointerUp(routine->sizeOfParametersAndReturnType);
    restoreSpilledRegisters(spilledRegisters);
}