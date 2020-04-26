#include <iostream>

#include "Negative.h"
#include "../global.h"

Negative::Negative(Expression* p_originalExpression)
{
    originalExpression = p_originalExpression;
}

void Negative::print()
{
    std::cout << " - ";
    originalExpression->print();
}

Register Negative::emit()
{
    if (originalExpression->getPrimitiveType() == INTEGER)
    {
        Register originalValue = originalExpression->emit();
        Register negativeOne = rp.getRegister();
        std::cout << "li " << negativeOne.getName() << " -1\n";
        std::cout << "mult " << originalValue.getName() << " " << negativeOne.getName() << "\n";
        rp.returnRegister(negativeOne);
        std::cout << "mflo " << originalValue.getName() << "\n";
        return originalValue;
    }
    else throw std::runtime_error("Negative::emit() - can't get the negative value of a expression that's not an integer");
}

int Negative::getValue()
{
    if (!originalExpression->isCTV()) throw std::runtime_error("Negative::getValue() - Can't get value if operand is not CTV");
    if (originalExpression->getPrimitiveType() != INTEGER) throw std::runtime_error("Negative::getValue() - type indicator is not INTEGER");
    return originalExpression->getValue() * -1;
}
