//
// Created by abeeston on 3/7/20.
//

#ifndef COMPILERS_LVALUEIDENT_H
#define COMPILERS_LVALUEIDENT_H

#include <string>

#include "LValue.h"

struct LValueIdent:LValue
{
    std::string* ident;
    LValueIdent(std::string*);
    void print() override;
};
#endif //COMPILERS_LVALUEIDENT_H
