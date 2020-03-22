#include <iostream>

#include "LookUpItem.h"
#include "types/SimpleType.h"
#include "../../global.h"

LookUpItem::LookUpItem() {}

LookUpItem::LookUpItem(std::string p_ident, Expression* p_expression) // called by Constants
{
    ident = p_ident;
    value = p_expression;
    offset = -1;
    baseRegister = "Error: constants do not have a base register.\n";
    type = generateBaseType();
}

void LookUpItem::print()
{
    std::cout << "[Look Up Item print, this should be overriden]\n";
}

BaseType LookUpItem::generateBaseType()
{
    if (value->typeIndicator == 0) return SimpleType(new std::string("integer"));
    else if (value->typeIndicator == 1) return SimpleType(new std::string("char"));
    else if (value->typeIndicator == 2) return SimpleType(new std::string("string"));
    else if (value->typeIndicator == 3) return SimpleType(new std::string("boolean"));
    else
    {
        std::cout << "Error constructing a BaseType from a constant (since it inherits from LookUpItem, which needs a BaseType), and the expression isn't of a primitive type\n";
        return BaseType();
    }
}

Register LookUpItem::emit()
{
    if (offset == -1) return value->emit(); // emit a constant
    else // emit a variable
    {
        Register r = rp.getRegister();
        std::cout << "lw " << r.getName() << " " << offset << "(" << baseRegister << ")   # load a variable\n";
        return r;
    }
}
