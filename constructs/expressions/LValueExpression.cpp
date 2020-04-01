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
    if (entry.lValueType == PRIMITIVE_TYPE)
    {
        if (entry.offset == -1) return entry.value->emit();
        else
        {
            Register r = rp.getRegister();
            std::cout << "lw " << r.getName() << " " << entry.offset << "(" << entry.baseRegister.getName() << ")   # load a variable\n";
            return r;
        }
    }
    else if (entry.lValueType == ARRAY_TYPE)
    {
        Register r = rp.getRegister();
        Register baseRegister = lValue->getBaseRegister();
        std::cout << "lw " << r.getName() << " " << entry.offset << "(" << baseRegister.getName() << ")   # loaded an array element\n";
        rp.returnRegister(baseRegister);
        return r;
    }
    else return Register();
}

int LValueExpression::getValue()
{ // LOCATION OF BUG; has to be pre-mature accessing of the st before things were added to it. What else could it possibly be? Make sure I'm not calling this in the constructor of any construct
    Entry entry = st.retrieveEntry(lValue->getKey());
    if (entry.offset == -1) return entry.value->getValue();
    else throw std::runtime_error("can't call LValueExpression::getValue() if the lValue points to a variable. Expression::getValue() is for constants only");
}