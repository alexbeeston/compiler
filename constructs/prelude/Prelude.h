//
// Created by abeeston on 2/20/20.
//

#ifndef COMPILERS_PRELUDE_H
#define COMPILERS_PRELUDE_H

#include <vector>
#include "constants/Constant.h"
#include "types/TypeDeclItem.h"
#include "TypedList.h"

struct Prelude
{
    std::vector<Constant*>* constants;
    std::vector<TypeDeclItem*>* types;
    std::vector<TypedList*>* vars;
    Prelude(std::vector<Constant*>*, std::vector<TypeDeclItem*>*, std::vector<TypedList*>*);
};
#endif //COMPILERS_PRELUDE_H
