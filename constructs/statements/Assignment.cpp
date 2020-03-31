#include <iostream>
#include <string>

#include "../../global.h"
#include "Assignment.h"

Assignment::Assignment(LValue* p_lValue, Expression* p_expression)
{
    lValue = p_lValue;
    expression = p_expression;
}

void Assignment::print()
{
    lValue->print();
    std::cout << ":=";
    expression->print();
}

void Assignment::emit()
{
    // load the Entry
    Entry entry = st.retrieveEntry(lValue->getKey());

    // error checking
    if (entry.offset == -1) throw std::runtime_error("Can not assign to a constant\n");
    else if (entry.type->getTypeIndicator() != expression->getTypeIndicator()) throw std::runtime_error("Attempting to assign an expression of typeIndicator " + std::to_string(expression->getTypeIndicator()) + " to a entry with typeindicator " + std::to_string(entry.type->typeIndicator) + ".\n");

    // emit
    std::cout << "# assignment\n";
    Register valueRegister = expression->emit();
    Register baseRegister = lValue->loadBaseRegister();

    std::cout << "sw " << valueRegister.getName() << " " << entry.offset << "(" << baseRegister.getName() << ")\n\n";
    rp.returnRegister(valueRegister);
}

