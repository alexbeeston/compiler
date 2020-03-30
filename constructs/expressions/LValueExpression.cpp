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

TypeIndicator LValueExpression::getTypeIndicator() { return st.retrieveItem(lValue->getKey()).type->getTypeIndicator(); }

Register LValueExpression::emit()
{
    return st.retrieveItem(lValue->getKey()).emit();
}



int LValueExpression::getValue()
{ // LOCATION OF BUG; has to be pre-mature accessing of the st before things were added to it. What else could it possibly be? Make sure I'm not calling this in the constructor of any construct
    std::string key = lValue->getKey();
    LookUpItem l = st.retrieveItem(key); // error happens inside the call to this function
//    if (l.value == nullptr) std::cout << "flag\n";
//    Expression* expressionContainingValue = st.retrieveItem(lValue->getKey()).value;
//    if (expressionContainingValue == nullptr) throw std::runtime_error("Attempting to get an expression on a lookUpItem, but the expression is nullptr. Likely, this LookUpItem represents a variable, not a constant");
//    else return expressionContainingValue->getValue();
    return 999999;
}