//
// Created by abeeston on 2/20/20.
//

#ifndef COMPILERS_PRELUDE_H
#define COMPILERS_PRELUDE_H

#include <vector>
#include "constants/Constant.h"
#include "types/BaseType.h"
#include "vars/Var.h"

struct Prelude
{
    std::vector<Constant*>* constants;
    std::vector<BaseType*>* types;
    Prelude(std::vector<Constant*>*, std::vector<BaseType*>*);
};
#endif //COMPILERS_PRELUDE_H
