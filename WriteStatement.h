#include "Statement.h"
#include "Expression.h"
#include <vector>

struct WriteStatement : Statement
{
   std::vector<Expression*>* expressions;
   WriteStatement (Expression* p_firstExpression, std::vector<Expression*>* p_extraExpressions)
   {
       expressions->push_back(p_firstExpression);
       for (Expression* extraExpression : *p_extraExpressions)
       {
           expressions->push_back(extraExpression);
       }
   }
};