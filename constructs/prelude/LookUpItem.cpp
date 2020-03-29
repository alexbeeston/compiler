#include <iostream>

#include "LookUpItem.h"
#include "types/SimpleType.h"
#include "../../global.h"

LookUpItem::LookUpItem() {}

LookUpItem::LookUpItem(std::string p_ident, Expression* p_expression, bool p_isRedeclarable) // called by constants
{
    ident = p_ident;
    value = p_expression;
    isRedeclarable = p_isRedeclarable;
    offset = -1;
    type = generateBaseType();
}

LookUpItem::LookUpItem(std::string p_ident, BaseType p_type, int p_offset) // called by variables
{
    ident = p_ident;
    type = p_type;
    isRedeclarable = false;
    offset = p_offset;
    baseRegister = rp.getGlobalPointer(); // assumes all variables are offset from the global pointer
}

void LookUpItem::print()
{
    std::cout << "[Look Up Item print, this should be overriden]\n";
}

BaseType LookUpItem::generateBaseType()
{
    // error here: before, calling getTypeIndicator() resulted in an error. Try again to see if it works next time you see this.
    if (value->typeIndicator == INTEGER) return SimpleType(new std::string("integer"));
    else if (value->typeIndicator == CHAR) return SimpleType(new std::string("char"));
    else if (value->typeIndicator == STRING) return SimpleType(new std::string("string"));
    else if (value->typeIndicator == BOOLEAN) return SimpleType(new std::string("boolean"));
    else
    {
        std::cout << "Error constructing a BaseType from a constant (since it inherits from LookUpItem, which needs a BaseType), and the expression isn't of a primitive type\n";
        return BaseType();
    }
}

Register LookUpItem::emit()
{
    // emit, or load, a constant
    if (offset == -1)
    {
        return value->emit();
    }
    // emit, or load, a variable
    else
    {
        Register r = rp.getRegister();
        std::cout << "lw " << r.getName() << " " << offset << "(" << baseRegister.getName() << ")   # load a variable\n";
        return r;
    }
}

Register LookUpItem::loadBaseRegister()
{
    if (type.getLValueType() == 0)
    {
        return Register();
    }
    return Register();

    // the LookUpItem is an array


    // the LookUpItem is a record
}
