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
    std::cout << "lw " << r.getName() << " " << lValue->getOffset() << "(" << lValue->getBaseRegister().getName() << ")   # loaded an LValueExpression\n";
    return r;
}

int LValueExpression::getValue()
{ // LOCATION OF BUG; has to be pre-mature accessing of the st before things were added to it. What else could it possibly be? Make sure I'm not calling this in the constructor of any construct
    Entry entry = st.retrieveEntry(lValue->getKey());
    if (entry.offset == -1) return entry.value->getValue();
    else throw std::runtime_error("can't call LValueExpression::getValue() if the lValue points to a variable. Expression::getValue() is for constants only");
}