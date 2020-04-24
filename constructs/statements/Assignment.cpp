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
    Entry entry = st.retrieveEntry(lValue->getKey());
    if (entry.offset == -1) throw std::runtime_error("Can not assign to a constant\n");
    if (lValue->getStyle() != expression->getStyle()) throw std::runtime_error("Assignment::emit() - styles of LValue and Expression in an assignment do not match. LValue = " + std::to_string(lValue->getStyle()) + ", expression = " + std::to_string(expression->getStyle()));
    std::cout << "# assignment\n";
    int leftOffset = lValue->getOffset();
    Register leftBase = lValue->getBaseRegister();

    if (lValue->getStyle() == PRIMITIVE_TYPE)
    {
        if (lValue->getTypeIndicator() != expression->getTypeIndicator()) throw std::runtime_error("Assignment::emit() - attempting to assign a primitive LValue, the left operand has type " + std::to_string(lValue->getTypeIndicator()) + " and right operand has type " + std::to_string(expression->getTypeIndicator()));
        Register staging = expression->emit();
        std::cout << "sw " << staging.getName() << " " << leftOffset << "(" << leftBase.getName() << ")\n\n";
        rp.returnRegister(staging);
    }
    else if (lValue->getStyle() == ARRAY_TYPE || lValue->getStyle() == RECORD_TYPE)
    {
        LValue* rightLValue = (dynamic_cast<LValueExpression*>(expression))->lValue;
        int leftSize = lValue->getInnerMostType()->computeSize();
        int rightSize = rightLValue->getInnerMostType()->computeSize();
        if (leftSize != rightSize) throw std::runtime_error("Assignment::emit() - sizes of left of right LValues don't match. Left size is " + std::to_string(leftSize) + " and right size is " + std::to_string(rightSize) + ".");
        Register rightBase = rightLValue->getBaseRegister();
        int rightOffset = rightLValue->getOffset(); // will copy this into a utilities file for copying contiguous memory; will be used in function calls I think for copying to stack, or something
        Register staging = rp.getRegister();
        static int WORD_SIZE = 4;
        for (int i = 0; i < leftSize; i += WORD_SIZE)
        {
            std::cout << "lw " << staging.getName() << " " << rightOffset + i << "(" << rightBase.getName() << ")   # load continuous memory block\n";
            std::cout << "sw " << staging.getName() << " " << leftOffset + i << "(" << leftBase.getName() << ")   # store continuous memory block\n";
        }
        std::cout << "# end continuous memory block copy\n\n";
        rp.returnRegister(rightBase);
        rp.returnRegister(staging);
    }
    else throw std::runtime_error("Assignment::emit() - lValue is not primitive, nor of ARRAY_STYLE, nor of RECORD_STYLE");
    rp.returnRegister(leftBase);
}

