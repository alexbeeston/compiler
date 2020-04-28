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
    Register r = rp.getRegister();
    if (entry.label == CONSTANT)
    {
        if (entry.value->getPrimitiveType() == STRING) std::cout << "la " << r.getName() << " message";
        else std::cout << "li " << r.getName() << " ";
        std::cout << entry.value->getValue() << "   # loaded an Lvalue\n";
        r.containsAddress = false;
    }
    else if (entry.label == VARIABLE)
    {
        Register baseRegister = lValue->getBaseRegister();
        if (lValue->isPrimitive())
        {
            r.containsAddress = false;
            std::cout << "lw " << r.getName() << " " << lValue->getOffset() << "(" << baseRegister.getName() << ") # loaded primitive LValue\n";
        }
        else
        {
            r.containsAddress = true;
            r.space = lValue->getInnerMostType()->computeSize();
            std::cout << "la " << r.getName() << " (" << baseRegister.getName() << ")  # loaded address of non-primitive lValue\n";
        }
        rp.returnRegister(baseRegister);
    }
    else throw std::runtime_error("LValueExpression::emit() - entry label isn't a variable or constant");
    return r;
}

int LValueExpression::getValue()
{
    Entry entry = st.retrieveEntry(lValue->getKey());
    if (entry.label == CONSTANT) return entry.value->getValue();
    else throw std::runtime_error("can't call LValueExpression::getValue() if the lValue points to a variable. Expression::getValue() is for constants only");
}

bool LValueExpression::isCTV()
{
    if (st.retrieveEntry(lValue->getKey()).label == CONSTANT) return true;
    else return false;
}

TypeStyle LValueExpression::getStyle() { return lValue->getStyle(); }