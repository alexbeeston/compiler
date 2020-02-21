#include "Expression.h"
#include "NumericLit.h"

NumericLit::NumericLit(char* p_numericLitValue) : Expression (p_numericLitValue)
{
    numericLitValue = p_numericLitValue;
}