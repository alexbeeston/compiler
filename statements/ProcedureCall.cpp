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
    auto spilledRegisters = spillRegisters();
    BaseType* type = st.retrieveRoutine(*ident)->type_temp;
    int sizeOfReturnType = 0;
    if (type != nullptr) sizeOfReturnType = type->computeSize();
    int sizeOfParameters = addParametersToStack(*ident, *expressions, sizeOfReturnType);
    std::cout << "# Call the function\n";
    std::cout << "jal " << *ident << "\n\n";
    deallocateParameters(sizeOfParameters);
    restoreSpilledRegisters(spilledRegisters);
}