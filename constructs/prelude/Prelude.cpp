#include "Prelude.h"

Prelude::Prelude(std::vector<Constant*>* p_constants, std::vector<TypeDeclItem*>* p_types, std::vector<TypedList*>* p_vars)
{
   constants = p_constants;
   types = p_types;
   vars = p_vars;
}
