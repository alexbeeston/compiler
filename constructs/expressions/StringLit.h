//
// Created by abeeston on 2/20/20.
//

#ifndef COMPILERS_STRINGLIT_H
#define COMPILERS_STRINGLIT_H

#include <string>

#include "Expression.h"

struct StringLit : Expression
{
    std::string stringLitValue;
    StringLit(char* p_value);
    void print() override;
    void emitLabel() override;
};
#endif //COMPILERS_STRINGLIT_H
