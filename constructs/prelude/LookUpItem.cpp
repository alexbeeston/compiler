#include <iostream>

#include "LookUpItem.h"

LookUpItem::LookUpItem() {}

LookUpItem::LookUpItem(std::string p_ident, BaseType p_type)
{
    ident = p_ident;
    type = p_type;
}

void LookUpItem::print()
{
    std::cout << "[Look Up Item print, this should be overriden]\n";
}