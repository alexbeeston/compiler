#include <iostream>

#include "LValueExpression.h"
#include "../../global.h"

LValueExpression::LValueExpression(LValue* p_lValue)
{
    typeIndicator = ALIAS;
    lValue = p_lValue;
}

void LValueExpression::print()
{
    lValue->print();
}

TypeIndicator LValueExpression::getTypeIndicator() { return lValue->getTypeIndicator(); }

Register LValueExpression::emit()
{
    Entry entry = st.retrieveEntry(lValue->getKey());
    Register r = rp.getRegister();
    if (entry.label == CONSTANT)
    {
        if (entry.value->getTypeIndicator() == STRING) std::cout << "la " << r.getName() << " message";
        else std::cout << "li " << r.getName() << " ";
        std::cout << entry.value->getValue() << "   # loaded an LValueExpression String Constant\n";
    }
    else if (entry.label == VARIABLE)
    {
        int offset = lValue->getOffset();
        Register baseRegister = lValue->getBaseRegister();
        std::cout << "lw " << r.getName() << " " << offset << "(" << baseRegister.getName() << ")   # loaded an LValueExpression Variable\n";
        rp.returnRegister(baseRegister);
    }
    else throw std::runtime_error("Entry's label isn't a variable or constant");
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

Style LValueExpression::getStyle() { return lValue->getStyle(); }