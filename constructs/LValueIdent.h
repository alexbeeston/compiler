//
// Created by abeeston on 3/7/20.
//

#ifndef COMPILERS_LVALUEIDENT_H
#define COMPILERS_LVALUEIDENT_H

#include <string>

#include "LValueBase.h"

struct LValueIdent:LValueBase
{
    std::string* ident;
    LValueIdent(char*);
    void print() override;
};
#endif //COMPILERS_LVALUEIDENT_H
