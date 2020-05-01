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
    static int RETURN_TYPE_SIZE = 0;
    addParametersToStack(*ident, *expressions, RETURN_TYPE_SIZE);
    std::cout << "# Call the procedure\n";
    std::cout << "jal " << *ident << "\n\n";
    deallocateParameters(routine->sizeOfParametersAndReturnType);
    restoreSpilledRegisters(spilledRegisters);
}