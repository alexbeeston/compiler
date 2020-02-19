#include "Statement.h"
#include "Expression.h"
#include <vector>

struct WhileStatement : Statement
{
    Expression *whileExpression;
    std::vector<Statement *> *statements;
};
