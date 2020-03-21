#include <iostream>

#include "LookUpItem.h"
#include "types/SimpleType.h"
#include "../../global.h"

LookUpItem::LookUpItem() {}

LookUpItem::LookUpItem(std::string p_ident, Expression p_expression) // called by Constants
{
    ident = p_ident;
    value = p_expression;
    offset = -1;
    baseRegister = "Error: constants do not have a base register.\n";
    type = generateBaseType(p_expression);
}

void LookUpItem::print()
{
    std::cout << "[Look Up Item print, this should be overriden]\n";
}

BaseType LookUpItem::generateBaseType(Expression e)
{
    if (e.typeIndicator == 0) return SimpleType(new std::string("integer"));
    else if (e.typeIndicator == 1) return SimpleType(new std::string("char"));
    else if (e.typeIndicator == 2) return SimpleType(new std::string("string"));
    else if (e.typeIndicator == 3) return SimpleType(new std::string("boolean"));
    else
    {
        std::cout << "Error constructing a BaseType from a constant (since it inherits from LookUpItem, which needs a BaseType), and the expression isn't of a primitive type\n";
        return BaseType();
    }
}

Register LookUpItem::emit(Register r)
{
    if (offset == -1)
    {
        if (value.typeIndicator == 2) std::cout << "la " << r.getName() << " message" << value.value << "   # loaded a string constant\n";
        else std::cout << "li " << r.getName() << " " << value.value << "   # load a constant\n";
    }
    else std::cout << "lw " << r.getName() << " " << offset << "(" << baseRegister << ")   # load a variable\n";
    return r;
}
