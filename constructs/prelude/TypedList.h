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
   std::vector<char*>* identList;
   BaseType* type;
   TypedList(std::vector<char*>*, BaseType*);
   void print();
};
#endif //COMPILERS_TYPEDLIST_H
