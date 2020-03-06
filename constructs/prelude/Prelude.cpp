#include "Prelude.h"

Prelude::Prelude(std::vector<Constant*>* p_constants, std::vector<TypeDeclItem*>* p_types, std::vector<TypedList*>* p_vars)
{
   constants = p_constants;
   types = p_types;
   vars = p_vars;
}

void Prelude::print()
{
    if (constants != nullptr)
    {
        std::cout << "CONST\n";
        for (Constant* item : *constants) { item->print(); }
    }

    std::cout << "\nTYPE" << std::endl;
    for (TypeDeclItem* item : *types) { item->print(); }

    std::cout << "\nVAR" << std::endl;
    for (TypedList* item : *vars) { item->print(); }
}
