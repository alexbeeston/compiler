#include "Prelude.h"

Prelude::Prelude(std::vector<Constant*>* p_constants, std::vector<TypeDeclItem*>* p_types, std::vector<TypedList*>* p_vars)
{
   constants = p_constants;
   types = p_types;
   vars = p_vars;
}

void Prelude::print()
{
    std::cout << "CONST" << std::endl;
    for (Constant* item : *constants) { item->print(); }

    std::cout << "\nTYPE" << std::endl;
    for (TypeDeclItem* item : *types) { item->print(); }

    std::cout << "\nVAR" << std::endl;
    for (TypedList* item : *vars)
    {
        std::cout << "Identifiers in this typelist:";
        item->print();
        std::cout << std::endl;
    }
}
