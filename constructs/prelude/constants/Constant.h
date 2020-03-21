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
    Constant();
    Constant(char*, Expression*);
    Constant(std::string, Expression*);
    void print();
    BaseType generateBaseType(Expression);
    Register emit() override;
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
