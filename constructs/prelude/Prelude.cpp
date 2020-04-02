#include <string>

#include "Prelude.h"

Prelude::Prelude(std::vector<Constant*>* p_constants, std::vector<DeclaredType*>* p_types, std::vector<TypedList*>* p_vars)
{
   constants = p_constants;
   declaredTypes = p_types;
   vars = p_vars;
}

void Prelude::print()
{
    if (constants != nullptr)
    {
        std::cout << "CONST\n";
        for (Constant* item : *constants) { item->print(); }
        std::cout << std::endl;
    }
    if (declaredTypes != nullptr)
    {
        std::cout << "TYPE" << std::endl;
        for (DeclaredType* item : *declaredTypes) { item->print(); }
        std::cout << std::endl;
    }
    if (vars != nullptr)
    {
        std::cout << "VAR" << std::endl;
        for (TypedList* item : *vars) { item->print(); std::cout << "\n"; }
        std::cout << std::endl;
    }
}
