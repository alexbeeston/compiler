#include <iostream>
#include "../../global.h"
#include "../prelude/variables/Variable.h"
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
    Register r = expression->emit();
    if (item.offset == -1) std::cout << "Error: can not assign to a constant\n";
    else std::cout << "sw " << r.getName() << " " << item.offset << "(" << item.baseRegister << ")\n\n";
    rp.returnRegister(r);
}

