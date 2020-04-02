#include "DeclaredType.h"

DeclaredType::DeclaredType(char* p_identifier, BaseType* p_type)
{
   identifier = std::string(p_identifier);
   type = p_type;
}

void DeclaredType::print()
{

}

