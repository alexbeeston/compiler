#include <iostream>
#include <string>
#include <map>
#include <types/SimpleType.h>
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
    // validate
    auto routine = st.retrieveRoutine(*ident);
    if (routine->type_temp == nullptr) throw std::runtime_error("FunctionCall::emit() - the function has nullptr for a return type");

    // continue
    auto spilledRegisters = spillRegisters();
    BaseType* returnType = routine->type_temp;
    addParametersToStack(*ident, *params, returnType->computeSize());
    std::cout << "# Call the function\n";
    std::cout << "jal " << *ident << "\n\n";

    // hang onto the return value
    Register valueRegister = rp.getRegister();
    valueRegister.containsAddress = true;
    valueRegister.space = returnType->computeSize();
    std::cout << "la " << valueRegister.getName() << " 0(" << rp.getStackPointer().getName() << ")\n";

    // continue with function calling
    deallocateParameters(routine->sizeOfParametersAndReturnType);
    restoreSpilledRegisters(spilledRegisters);
    return valueRegister;
}

PrimitiveType FunctionCall::getPrimitiveType()
{
    BaseType* returnType = st.retrieveRoutine(*ident)->type_temp;
    if (returnType->style == SIMPLE)
    {
        auto simpleReturnType = dynamic_cast<SimpleType*>(returnType);
        return simpleReturnType->typeIndicator;
    }
    else return NOT_PRIMITIVE;
}
