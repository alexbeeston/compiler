#include "Constant.h"
#include "expression/Expression.h"

Constant::Constant(char* p_identifier, Expression* p_value)
{
    identifier = p_identifier;
    value = p_value;
}
