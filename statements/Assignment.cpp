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
    // validation
    Entry entry = st.retrieveEntry(lValue->getKey());
    if (entry.label == CONSTANT) throw std::runtime_error("Can not assign to a constant\n");
    if (lValue->getStyle() != expression->getStyle()) throw std::runtime_error("Assignment::emit() - styles of LValue and Expression in an assignment do not match. LValue = " + std::to_string(lValue->getStyle()) + ", expression = " + std::to_string(expression->getStyle()));

    // assign to memory
    std::cout << "# assignment\n";
    int leftOffsetStart = lValue->getOffset();
    Register leftBase = lValue->getBaseRegister();
    Register expressionRegister = expression->emit();
    if (lValue->isPrimitive())
    {
        // validation
        if (lValue->getPrimitiveType() != expression->getPrimitiveType()) throw std::runtime_error("Assignment::emit() - attempting to assign a primitive LValue, the lLValue operand has type " + std::to_string(lValue->getPrimitiveType()) + " and expression operand has type " + std::to_string(expression->getPrimitiveType()));
        if (expressionRegister.containsAddress) throw std::runtime_error("Assignment::emit() - attempting to assign to a primitive LValue, but the register returned by the expression contains an address");

        // copy memory
        std::cout << "sw " << expressionRegister.getName() << " " << leftOffsetStart << "(" << leftBase.getName() << ") # assigned to a primitive LValue\n";
        rp.returnRegister(expressionRegister);
    }
    else
    {
        // validation
        if (!expressionRegister.containsAddress) throw std::runtime_error("Assignment::emit() - attempting to assign to a non-primitive LValue, but the register returned by the expression does not contain an address");
        int leftSize = lValue->getInnerMostType()->computeSize();
        if (leftSize != expressionRegister.space) throw std::runtime_error("Assignment::emit() - assigning a non-primitive expression to an lvalue, but sizes don't match. Left size is " + std::to_string(leftSize) + " and right size is " + std::to_string(expressionRegister.space));

        // copy memory block
        static int RIGHT_OFFSET = 0;
        copyContinuousMemory(leftOffsetStart, RIGHT_OFFSET, expressionRegister.space, leftBase, expressionRegister);
    }
    std::cout << std::endl;
    rp.returnRegister(leftBase);
}
