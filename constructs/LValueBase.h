//
// Created by abeeston on 3/7/20.
//

#ifndef COMPILERS_unique_guard_for_LValueBase
#define COMPILERS_unique_guard_for_LValueBase

struct LValueBase
{
    LValueBase();
    virtual void print();
    std::string keyString;
};
#endif //COMPILERS_unique_guard_for_LValueBase
