#include <iostream>

#include "LValueExpression.h"
#include "../../symbolTable/SymbolTable.h"

extern SymbolTable st;

LValueExpression::LValueExpression(LValue* p_lValue)
{
    lValue = p_lValue;
}

void LValueExpression::print()
{
    lValue->print();
}

Register LValueExpression::emit()
{
    Variable var = st.retrieveVariable(lValue->getKey());
    Register r = rp.getRegister();
    std::cout << "lw " << r.name << " " << var.offset << "(" << var.baseRegister << ")\n";
    return r;
}