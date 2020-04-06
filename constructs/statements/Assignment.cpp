#include <iostream>
#include <string>

#include "../../global.h"
#include "Assignment.h"
#include "../../constructs/expressions/LValueExpression.h"

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
    // load the Entry
    Entry entry = st.retrieveEntry(lValue->getKey());
    if (entry.offset == -1) throw std::runtime_error("Can not assign to a constant\n");
    if (lValue->getStyle() != expression->getStyle()) throw std::runtime_error("Assignment::emit() - styles of LValue and Expression in an assignment do not match.");
    std::cout << "# assignment\n";
    int leftOffset = lValue->getOffset();
    Register leftBase = lValue->getBaseRegister();

    if (lValue->getStyle() == PRIMITIVE_TYPE)
    {
        if (lValue->getTypeIndicator() != expression->getTypeIndicator()) throw std::runtime_error("Assignment::emit() - attempting to assign to a primitive LValue type, but the type Indicators are not the same");
        Register staging = expression->emit();
        std::cout << "sw " << staging.getName() << " " << leftOffset << "(" << leftBase.getName() << ")\n\n";
        rp.returnRegister(staging);
        if (leftBase.getName().compare("$gp") != 0) rp.returnRegister(leftBase);
    }
    else if (lValue->getStyle() == ARRAY_TYPE || lValue->getStyle() == RECORD_TYPE)
    {
        LValue* rightLValue = (dynamic_cast<LValueExpression*>(expression))->lValue;
        int leftSize = lValue->getInnerMostType()->computeSize();
        int rightSize = rightLValue->getInnerMostType()->computeSize();
        if (leftSize != rightSize) throw std::runtime_error("Assignment::emit() - sizes of left of right LValues don't match");

        Register rightBase = rightLValue->getBaseRegister();
        int rightOffset = rightLValue->getOffset();
        Register staging = rp.getRegister();
        for (int i = 0; i < leftSize; i += 4)
        {
            std::cout << "lw " << staging.getName() << " " << rightOffset + i << "(" << rightBase.getName() << ")   # load continuous memory block\n";
            std::cout << "sw " << staging.getName() << " " << leftOffset + i << "(" << leftBase.getName() << ")   # store continuous memory block\n";
        }
        std::cout << "# end continuous memory block copy\n\n";
    }
    else if (lValue->getStyle() == ALIAS_TYPE) throw std::runtime_error("Assignment::emit() - lValue->getStyle() return ALIAS_TYPE; this should have been replaced with a non-Alias type in LValue::getStyle()");
    else throw std::runtime_error("Assignment::emit() - lValue->getStyle() doesn't return a recognied style");
}

