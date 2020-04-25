#include "DeclaredType.h"

DeclaredType::DeclaredType(char* p_identifier, BaseType* p_type)
{
   identifier = std::string(p_identifier);
   type = p_type;
}

DeclaredType::DeclaredType(std::string p_identifier, BaseType* p_type)
{
    identifier = p_identifier;
    type = p_type;
}

void DeclaredType::print()
{

}

