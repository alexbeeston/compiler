#include <iostream>

#include "TypeDeclItem.h"
#include "BaseType.h"

TypeDeclItem::TypeDeclItem(std::string* p_ident, BaseType* p_type)
{
   ident = p_ident;
   type = p_type;
}

void TypeDeclItem::print()
{
    std::cout << *ident << " = ";
    type->print();
    std::cout << std::endl;
}
