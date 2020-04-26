#include <iostream>
#include <string>

#include "../global.h"
#include "Assignment.h"
#include "../expressions/LValueExpression.h"
#include "../miscellaneous/utilities.h"

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
    Entry entry = st.retrieveEntry(lValue->getKey());
    if (entry.label == CONSTANT) throw std::runtime_error("Can not assign to a constant\n");
    if (lValue->getStyle() != expression->getStyle()) throw std::runtime_error("Assignment::emit() - styles of LValue and Expression in an assignment do not match. LValue = " + std::to_string(lValue->getStyle()) + ", expression = " + std::to_string(expression->getStyle()));
    std::cout << "# assignment\n";
    int leftAddress = lValue->getOffset();
    Register leftBase = lValue->getBaseRegister();

    if (lValue->isPrimitive())
    {
        if (lValue->getTypeIndicator() != expression->getTypeIndicator()) throw std::runtime_error("Assignment::emit() - attempting to assign a primitive LValue, the lLValue operand has type " + std::to_string(lValue->getTypeIndicator()) + " and expression operand has type " + std::to_string(expression->getTypeIndicator()));
        Register staging = expression->emit();
        std::cout << "sw " << staging.getName() << " " << leftAddress << "(" << leftBase.getName() << ")\n\n";
        rp.returnRegister(staging);
    }
    else if (lValue->getStyle() == ARRAY_TYPE || lValue->getStyle() == RECORD_TYPE)
    {
        LValue* rightLValue = (dynamic_cast<LValueExpression*>(expression))->lValue;
        int leftSize = lValue->getInnerMostType()->computeSize();
        int rightSize = rightLValue->getInnerMostType()->computeSize();
        if (leftSize != rightSize) throw std::runtime_error("Assignment::emit() - sizes of left of right LValues don't match. Left size is " + std::to_string(leftSize) + " and right size is " + std::to_string(rightSize) + ".");
        Register rightBase = rightLValue->getBaseRegister();
        int rightAddress = rightLValue->getOffset();
        copyContinuousMemory(leftAddress, rightAddress, leftSize, leftBase, rightBase);
        rp.returnRegister(rightBase);
    }
    else throw std::runtime_error("Assignment::emit() - lValue is not primitive, nor of ARRAY_STYLE, nor of RECORD_STYLE");
    rp.returnRegister(leftBase);
}
