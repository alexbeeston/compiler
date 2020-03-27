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
    std::cout << "# assignment\n";
    LookUpItem item = st.retrieveItem(lValue->getKey());
//    std::cout << "# type indicator of LValue: " << item.type.typeIndicator << " and type indicator of expression: " << expression->getTypeIndicator() << "\n";
    if (item.type.typeIndicator != expression->getTypeIndicator()) throw std::runtime_error("Attempting to assign an expression of typeIndicator " + std::to_string(expression->getTypeIndicator()) + " to a LookUpItem with typeindicator " + std::to_string(item.type.typeIndicator) + ".\n");
    Register r = expression->emit();
    if (item.offset == -1) std::cout << "Error: can not assign to a constant\n";
    else std::cout << "sw " << r.getName() << " " << item.offset << "(" << item.baseRegister << ")\n\n";
    rp.returnRegister(r);
}

