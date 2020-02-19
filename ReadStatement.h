#include "Statement.h"
#include "LValue.h"
#include <vector>

struct ReadStatement : Statement
{
   std::vector<LValue*>* lValues;
   ReadStatement (LValue* initialValue, std::vector<LValue*>* extraValues)
   {
       lValues->push_back(initialValue);
       for (LValue* item : *extraValues)
       {
           lValues->push_back(item);
       }
   }
};