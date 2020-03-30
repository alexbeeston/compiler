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
    // load the LookUpItem
    LookUpItem lookUpItem = st.retrieveItem(lValue->getKey());

    // error checking
    if (lookUpItem.offset == -1) throw std::runtime_error("Can not assign to a constant\n");
    else if (lookUpItem.type->getTypeIndicator() != expression->getTypeIndicator()) throw std::runtime_error("Attempting to assign an expression of typeIndicator " + std::to_string(expression->getTypeIndicator()) + " to a LookUpItem with typeindicator " + std::to_string(lookUpItem.type->typeIndicator) + ".\n");

    // emit
    std::cout << "# assignment\n";
    Register valueRegister = expression->emit();
    Register baseRegister = lValue->loadBaseRegister();

    std::cout << "sw " << valueRegister.getName() << " " << lookUpItem.offset << "(" << baseRegister.getName() << ")\n\n";
    rp.returnRegister(valueRegister);
}

