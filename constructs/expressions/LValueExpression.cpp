#include <iostream>

#include "LValueExpression.h"
#include "../../global.h"

LValueExpression::LValueExpression(LValue* p_lValue)
{
    lValue = p_lValue;
}

void LValueExpression::print()
{
    lValue->print();
}

TypeIndicator LValueExpression::getTypeIndicator() { return st.retrieveEntry(lValue->getKey()).type->getTypeIndicator(); }

Register LValueExpression::emit()
{
    Entry entry = st.retrieveEntry(lValue->getKey());
    Register r = rp.getRegister();
    int offset = lValue->getOffset();
    Register baseRegister = lValue->getBaseRegister();
    std::cout << "lw " << r.getName() << " " << offset << "(" << baseRegister.getName() << ")   # loaded an LValueExpression\n";
    if (baseRegister.getName().compare("$gp") != 0) rp.returnRegister(baseRegister);
    return r;
}

int LValueExpression::getValue()
{
    Entry entry = st.retrieveEntry(lValue->getKey());
    if (entry.offset == -1) return entry.value->getValue();
    else throw std::runtime_error("can't call LValueExpression::getValue() if the lValue points to a variable. Expression::getValue() is for constants only");
}