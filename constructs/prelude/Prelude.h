//
// Created by abeeston on 2/20/20.
//

#ifndef COMPILERS_PRELUDE_H
#define COMPILERS_PRELUDE_H

#include <vector>
#include "constants/Constant.h"
#include "types/BaseType.h"
#include "variables/Variable.h"
#include "TypedList.h"

struct Prelude
{
    std::vector<Constant*>* constants;
    std::vector<BaseType*>* types;
    std::vector<Variable*>* vars;
    Prelude(std::vector<Constant*>*, std::vector<BaseType*>*, std::vector<TypedList*>*);
    void print();
};
#endif //COMPILERS_PRELUDE_H
