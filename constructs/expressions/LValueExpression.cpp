#include <iostream>

#include "LValueExpression.h"
#include "../../global.h"

LValueExpression::LValueExpression(LValue* p_lValue)
{
    lValue = p_lValue;
}

void LValueExpression::print()
{
    lValue->print();
}

int LValueExpression::getTypeIndicator() { return st.retrieveVariable(lValue->getKey()).type.typeIndicator; } // is there a better way to do this? An Lvalue is a just an identifier, dot operator, or index, so it doesn't inherently know its type

Register LValueExpression::emit()
{
    Variable var = st.retrieveVariable(lValue->getKey());
    Register r = rp.getRegister();
    std::cout << "lw " << r.name << " " << var.offset << "(" << var.baseRegister << ")\n";
    return r;
}