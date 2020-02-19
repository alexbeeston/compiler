#include "Expression.h"
#include "Statement.h"
#include <vector>

enum Location {TO, DOWNTO};

struct ForStatement : Statement
{
    char* ident;
    Expression* lowExpression;
    Location* location;
    Expression* highExpression;
    std::vector<Statement*>* statements;
    ForStatement (char* p_ident, Expression* p_lowExpression, Location* p_location, Expression* p_highExpression, std::vector<Statement*>* p_statements)
    {
        ident = p_ident;
        lowExpression = p_lowExpression;
        location = p_location;
        highExpression = p_highExpression;
        statements = p_statements;
    }
};