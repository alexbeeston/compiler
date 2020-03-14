#include <string>

#include "Prelude.h"

Prelude::Prelude(std::vector<Constant*>* p_constants, std::vector<TypeDeclItem*>* p_types, std::vector<TypedList*>* p_vars)
{
   constants = p_constants;
   types = p_types;
   if (p_vars != nullptr)
   {
       vars = new std::vector<Variable*>;
       for (TypedList* typedList : *p_vars)
       {
           for (std::string* identifier : *typedList->identList)
           {
               vars->push_back(new Variable(*identifier, Expression(), *typedList->type));
           }
       }
   }
   else
   {
       vars = nullptr;
   }
}

void Prelude::print()
{
    if (constants != nullptr)
    {
        std::cout << "CONST\n";
        for (Constant* item : *constants) { item->print(); }
        std::cout << std::endl;
    }
    if (types != nullptr)
    {
        std::cout << "TYPE" << std::endl;
        for (TypeDeclItem* item : *types) { item->print(); }
        std::cout << std::endl;
    }
    if (vars != nullptr)
    {
        std::cout << "VAR" << std::endl;
        for (Variable* item : *vars) { item->print(); std::cout << "\n"; }
        std::cout << std::endl;
    }
}
