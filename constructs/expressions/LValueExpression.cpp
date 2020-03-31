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
        Register baseRegister = lValue->loadBaseRegister();
        std::cout << "lw " << r.getName() << " " << entry.offset << "(" << baseRegister.getName() << ")   # loaded an array element\n";
        rp.returnRegister(baseRegister);
        return r;
    }


    // emit a record element
}



int LValueExpression::getValue()
{ // LOCATION OF BUG; has to be pre-mature accessing of the st before things were added to it. What else could it possibly be? Make sure I'm not calling this in the constructor of any construct
    std::string key = lValue->getKey();
    Entry l = st.retrieveEntry(key); // error happens inside the call to this function
//    if (l.value == nullptr) std::cout << "flag\n";
//    Expression* expressionContainingValue = st.retrieveItem(lValue->getKey()).value;
//    if (expressionContainingValue == nullptr) throw std::runtime_error("Attempting to get an expression on a lookUpItem, but the expression is nullptr. Likely, this Entry represents a variable, not a constant");
//    else return expressionContainingValue->getValue();
    return 999999;
}