//
// Created by abeeston on 2/24/20.
//

#ifndef COMPILERS_TYPEDLIST_H
#define COMPILERS_TYPEDLIST_H

#include <vector>
#include <iostream>
#include <string>

#include "../types/BaseType.h"

struct TypedList
{
   std::vector<std::string*>* identList;
   BaseType* type;
   TypedList(std::vector<char*>*, BaseType*);
   TypedList(std::vector<std::string*>*, BaseType*);
   void print();
};
#endif //COMPILERS_TYPEDLIST_H
