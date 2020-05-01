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
    if (st.retrieveEntry(lValue->getKey()).label == CONSTANT) throw std::runtime_error("Assignment::emit() - can not assign to a constant\n");
    if (lValue->getStyle() != expression->getTypeStyle()) throw std::runtime_error("Assignment::emit() - styles of LValue and Expression in an assignment do not match. LValue = " + std::to_string(lValue->getStyle()) + ", expression = " + std::to_string(expression->getTypeStyle()));

    // assign to memory
    Register sourceRegister = expression->emit();
    Register targetBaseRegister = lValue->getBaseRegister();
    int targetOffset = lValue->getOffset();
    std::cout << "# assignment\n";
    if (sourceRegister.containsAddress)
    {
        // validate
        if (lValue->getInnerMostType()->computeSize() != sourceRegister.space) throw std::runtime_error("Assignment::emit() - assigning a non-primitive expression to an lvalue, but sizes don't match. Left size is " + std::to_string(lValue->getInnerMostType()->computeSize()) + " and right size is " + std::to_string(sourceRegister.space));

        // continue
        static int SOURCE_OFFSET = 0;
        copyContinuousMemory(targetOffset, SOURCE_OFFSET, sourceRegister.space, targetBaseRegister, sourceRegister);
    }
    else
    {
        // validate
        if (!lValue->isPrimitive()) throw std::runtime_error("Assignment::emit() - the register containing the evaluation of the expression contains a value, but the LValue is not primitive");
        if (lValue->getPrimitiveType() != expression->getPrimitiveType()) throw std::runtime_error("Assignment::emit() - attempting to assign a primitive LValue, the lLValue operand has type " + std::to_string(lValue->getPrimitiveType()) + " and expression operand has type " + std::to_string(expression->getPrimitiveType()));

        // continue
        std::cout << "sw " << sourceRegister.getName() << " " << targetOffset << "(" << targetBaseRegister.getName() << ")  # assigned a primitive expression to a primitive LValue\n";
    }
    rp.returnRegister(sourceRegister);
    rp.returnRegister(targetBaseRegister);
}
