#include <iostream>

#include "../../symbolTable/SymbolTable.h"
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
    std::cout << "[sw function] LValue::lookUpValue: " << lValue->getKey() << ", offset from base: \n";
}

/*
 * Lvalue return base register and function - sw and lw needs this
 *
 */