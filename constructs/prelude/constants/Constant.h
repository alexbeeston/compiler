//
// Created by abeeston on 2/20/20.
//

#ifndef COMPILERS_CONSTANT_H
#define COMPILERS_CONSTANT_H

#include <string>

#include "../../expressions/Expression.h"
#include "../LookUpItem.h"

struct Constant:LookUpItem
{
    Expression* value;
    Constant(char* p_identifier, Expression* p_value);
    void print();
    BaseType generateBaseType(Expression);
};
#endif //COMPILERS_CONSTANT_H

//struct LookUpItem
//{
//    std::string ident;
//    BaseType type;
//    LookUpItem();
//    LookUpItem(std::string, BaseType);
//    virtual void print();
//};
