//
// Created by abeeston on 2/20/20.
//

#ifndef COMPILERS_PRELUDE_H
#define COMPILERS_PRELUDE_H

#include <vector>
#include "constants/Constant.h"
#include "types/Type.h"
#include "vars/Var.h"

struct Prelude
{
    std::vector<Constant*>* constants;
    std::vector<Type*>* types;
    Prelude(std::vector<Constant*>* p_constants);
};
#endif //COMPILERS_PRELUDE_H
