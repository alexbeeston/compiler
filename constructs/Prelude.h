//
// Created by abeeston on 2/20/20.
//

#ifndef COMPILERS_PRELUDE_H
#define COMPILERS_PRELUDE_H

#include <vector>
#include "Constant.h"
#include "Type.h"
#include "Var.h"

struct Prelude
{
    std::vector<Constant*>* constants;
    std::vector<Type*>* types;
    std::vector<Var*>* vars;
    Prelude(std::vector<Constant*>* p_constants);
};
#endif //COMPILERS_PRELUDE_H
