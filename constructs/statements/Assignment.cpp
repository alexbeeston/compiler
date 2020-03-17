#include <iostream>

#include "../../symbolTable/SymbolTable.h"
#include "../prelude/variables/Variable.h"
#include "Assignment.h"

extern SymbolTable st;

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
    std::string location = expression->emit();
    st.testPrint();
//    Variable var = st.retrieveVariable(lValue->getKey());
//    std::cout << "[sw function] address: " << var.address << "\n";
}

/*
 * Lvalue return base register and function - sw and lw needs this
 *
 */