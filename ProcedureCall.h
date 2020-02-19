#include "Expression.h"
#include "Statement.h"
#include <vector>

struct ProcedureCall : Statement
{
    char* ident;
    std::vector< std::vector<Expression> > expressionLists;
};
