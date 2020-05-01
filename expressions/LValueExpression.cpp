#include <iostream>

#include "LValueExpression.h"
#include "../global.h"

LValueExpression::LValueExpression(LValue* p_lValue)
{
    typeIndicator = NOT_PRIMITIVE;
    lValue = p_lValue;
}

void LValueExpression::print()
{
    lValue->print();
}

PrimitiveType LValueExpression::getPrimitiveType() { return lValue->getPrimitiveType(); }

Register LValueExpression::emit()
{
    Entry entry = st.retrieveEntry(lValue->getKey());
    Register reg = rp.getRegister();
    if (entry.label == CONSTANT)
    {
        if (entry.value->getPrimitiveType() == STRING) std::cout << "la " << reg.getName() << " message";
        else std::cout << "li " << reg.getName() << " ";
        std::cout << entry.value->getValue() << "   # loaded an Lvalue\n";
        reg.containsAddress = false;
    }
    else if (entry.label == VARIABLE)
    {
        Register baseRegister = lValue->getBaseRegister();
        int offset = lValue->getOffset();
        if (lValue->isPrimitive())
        {
            reg.containsAddress = false;
            std::cout << "lw " << reg.getName() << " " << offset << "(" << baseRegister.getName() << ") # loaded primitive LValue\n";
        }
        else
        {
            reg.containsAddress = true;
            reg.space = lValue->getInnerMostType()->computeSize();
            std::cout << "la " << reg.getName() << " " << offset << "(" << baseRegister.getName() << ")  # loaded address of non-primitive lValue\n";
        }
        rp.returnRegister(baseRegister);
    }
    else throw std::runtime_error("LValueExpression::emit() - entry label isn't a variable or constant");
    return reg;
}

int LValueExpression::getValue()
{
    Entry entry = st.retrieveEntry(lValue->getKey());
    if (entry.label == CONSTANT) return entry.value->getValue();
    else throw std::runtime_error("can't call LValueExpression::getValue() if the lValue points to a variable. Expression::getValue() is for constants only");
}

bool LValueExpression::isCTV()
{
    return st.retrieveEntry(lValue->getKey()).label == CONSTANT;
}

TypeStyle LValueExpression::getTypeStyle() { return lValue->getStyle(); }