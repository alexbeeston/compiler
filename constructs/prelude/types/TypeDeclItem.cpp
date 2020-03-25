#include <iostream>

#include "TypeDeclItem.h"
#include "BaseType.h"

TypeDeclItem::TypeDeclItem() {}

TypeDeclItem::TypeDeclItem(std::string* p_ident, BaseType* p_type, bool p_isRedeclarable)
{
   ident = p_ident;
   type = p_type;
   isRedeclarable = p_isRedeclarable;
}

void TypeDeclItem::print()
{
    std::cout << *ident << " = ";
    type->print();
    std::cout << std::endl;
}
