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
    if (entry.label == CONSTANT) throw std::runtime_error("Assignment::emit() - can not assign to a constant\n");
    if (lValue->getStyle() != expression->getTypeStyle()) throw std::runtime_error("Assignment::emit() - styles of LValue and Expression in an assignment do not match. LValue = " + std::to_string(lValue->getStyle()) + ", expression = " + std::to_string(expression->getTypeStyle()));

    // assign to memory
    std::cout << "# assignment\n";
    Register sourceRegister = expression->emit();
    Register targetBaseRegister = lValue->getBaseRegister();
    int targetOffset = lValue->getOffset();

    // do all four combinations here maybe: targetBase and source base contains address or not.
    if (targetBaseRegister.containsAddress && !sourceRegister.containsAddress) std::cout << "sw " << sourceRegister.getName() << " 0(" << targetBaseRegister.getName() << ")\n";
    else if (sourceRegister.containsAddress)
    {
        // validate
        if (lValue->getInnerMostType()->computeSize() != sourceRegister.space) throw std::runtime_error("Assignment::emit() - assigning a non-primitive expression to an lvalue, but sizes don't match. Left size is " + std::to_string(lValue->getInnerMostType()->computeSize()) + " and right size is " + std::to_string(sourceRegister.space));

        // continue
        copyContinuousMemory(0, sourceRegister, targetOffset, targetBaseRegister, sourceRegister.space);
    }
    else
    {
        // validate
        if (!lValue->isPrimitive()) throw std::runtime_error("Assignment::emit() - the register containing the evaluation of the expression contains a value, but the LValue is not primitive");
        if (lValue->getPrimitiveType() != expression->resolvePrimitiveType()) throw std::runtime_error("Assignment::emit() - attempting to assign a primitive LValue, the lLValue operand has type " + std::to_string(lValue->getPrimitiveType()) + " and expression operand has type " + std::to_string(expression->resolvePrimitiveType()));

        // continue
        if (entry.passByReference)
        {
            Register destination = rp.getRegister();
            std::cout << "lw " << destination.getName() << " " << targetOffset << "(" << targetBaseRegister.getName() << ")\n";
            std::cout << "sw " << sourceRegister.getName() << " 0(" << destination.getName() << ")\n";
            rp.returnRegister(destination);
        }
        else std::cout << "sw " << sourceRegister.getName() << " " << targetOffset << "(" << targetBaseRegister.getName() << ")  # assigned a primitive expression to a primitive LValue\n";
    }
    rp.returnRegister(sourceRegister);
    rp.returnRegister(targetBaseRegister);
}
