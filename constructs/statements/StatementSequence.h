//
// Created by abeeston on 2/25/20.
//

#ifndef COMPILERS_STATEMENTSEQUENCE_H
#define COMPILERS_STATEMENTSEQUENCE_H

#include <vector>

#include "Statement.h"

struct StatementSequence
{
   std::vector<Statement*>* statements;
   StatementSequence(Statement*, std::vector<Statement*>*);
};
#endif //COMPILERS_STATEMENTSEQUENCE_H
