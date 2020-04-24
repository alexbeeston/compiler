//
// Created by abeeston on 2/20/20.
//

#ifndef COMPILERS_PRELUDE_H
#define COMPILERS_PRELUDE_H

#include <vector>
#include "Constant.h"
#include "../types/DeclaredType.h"
#include "TypedList.h"

struct Prelude
{
    std::vector<Constant*>* constants;
    std::vector<DeclaredType*>* declaredTypes;
    std::vector<TypedList*>* vars;
    Prelude(std::vector<Constant*>*, std::vector<DeclaredType*>*, std::vector<TypedList*>*);
    void print();
};
#endif //COMPILERS_PRELUDE_H
