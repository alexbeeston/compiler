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

std::string LValueExpression::emit()
{
    Variable var = st.retrieveVariable(lValue->getKey());
    std::cout << "lw $t0 " << var.offset << "(" << var.baseRegister << ")\n";
    return "$t0";
}