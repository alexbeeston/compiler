#include <iostream>
#include <string>
#include <map>
#include "FunctionCall.h"
#include "../global.h"
#include "../miscellaneous/utilities.h"

FunctionCall::FunctionCall(char* p_ident, std::vector<Expression*>* p_params)
{
    ident = new std::string(p_ident);
    params = p_params;
}

void FunctionCall::print()
{
    std::cout << *ident << "(";
    for (Expression* item : *params)
    {
        item->print();
        std::cout << ",";
    }
    std::cout << ")";
}

Register FunctionCall::emit()
{
    auto spilledRegisters = spillRegisters();
    BaseType* type = st.retrieveRoutine(*ident)->type_temp;
    int sizeOfReturnType = 0;
    if (type != nullptr) sizeOfReturnType = type->computeSize();
    int sizeOfParameters = addParametersToStack(*ident, *params, sizeOfReturnType);
    std::cout << "# Call the function\n";
    std::cout << "jal " << *ident << "\n\n";
    deallocateParameters(sizeOfParameters);
    restoreSpilledRegisters(spilledRegisters);
}

PrimitiveType FunctionCall::getPrimitiveType()
{
    return INTEGER; // must be replaced by consulting the st for the return type of the
}
