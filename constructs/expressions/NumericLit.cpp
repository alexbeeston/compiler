#include <string>

#include "Expression.h"
#include "NumericLit.h"

NumericLit::NumericLit(int p_numericLitValue) : Expression (p_numericLitValue)
{
    numericLitValue = p_numericLitValue;
}