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
    Register r = expression->emit();
    Variable var = st.retrieveVariable(lValue->getKey()); // assumes that the lValue refers to a variable
    std::cout << "sw " << r.name << " " << var.offset << "(" << var.baseRegister << ")\n";
}

