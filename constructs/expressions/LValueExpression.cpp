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
        std::cout << "li " << r.getName() << " " << entry.value->getValue() << "   # loaded an LValueExpression Constant\n";
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

Style LValueExpression::getStyle() { return lValue->getStyle(); }