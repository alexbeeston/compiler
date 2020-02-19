#include <iostream>
#include <vector>

#include "Expression.h"
#include "Statement.h"

struct ElseIf
{
    Expression* elseIfExpression;
    std::vector<Statement*>* elseIfStatements;
    ElseIf (Expression* p_elseIfExpression, std::vector<Statement*>* p_elseIfStatements)
    {
        elseIfExpression = p_elseIfExpression;
        elseIfStatements  = p_elseIfStatements;
    }
};

struct IfStatement : Statement
{
    Expression* ifExpression;
    std::vector<Statement*>* ifStatements;
    std::vector<ElseIf*>* elseIfBlocks;
    std::vector<Statement*>* elseStatements;
    IfStatement (Expression* p_ifExpression, std::vector<Statement*>* p_ifStatements, std::vector<ElseIf*>* p_elseIfBlocks, std::vector<Statement*>* p_elseStatements)
    {
        ifExpression = p_ifExpression;
        ifStatements = p_ifStatements;
        elseIfBlocks = p_elseIfBlocks;
        elseStatements = p_elseStatements;
    }
};