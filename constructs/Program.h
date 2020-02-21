#include <vector>
#include "Constant.h"
#include "Type.h"
#include "Var.h"
#include "Routine.h"
#include "Statement.h"

struct Program
{
    std::vector<Constant*>* constants;
    std::vector<Type*>* types;
    std::vector<Var*>* vars;
    std::vector<Routine*>* routines;
    std::vector<Statement*>* block;
public:
    Program();
};

