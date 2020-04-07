#include <iostream>

#include "Negative.h"
#include "../../global.h"

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
    if (originalExpression->getTypeIndicator() == INTEGER)
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
