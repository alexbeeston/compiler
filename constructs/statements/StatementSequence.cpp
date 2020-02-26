#include <vector>

#include "Statement.h"
#include "StatementSequence.h"

StatementSequence::StatementSequence(Statement* firstStatement, std::vector<Statement*>* extraStatements)
{
    statements = new std::vector<Statement*>{firstStatement};
    for (Statement* extraStatement : *extraStatements) statements->push_back(extraStatement);
}