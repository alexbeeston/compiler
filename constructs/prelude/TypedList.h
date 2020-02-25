//
// Created by abeeston on 2/24/20.
//

#ifndef COMPILERS_TYPEDLIST_H
#define COMPILERS_TYPEDLIST_H

#include <vector>
#include <iostream>
#include "types/BaseType.h"

struct TypedList
{
   std::vector<std::string> identList;
   BaseType type;
   TypedList();
};
#endif //COMPILERS_TYPEDLIST_H
