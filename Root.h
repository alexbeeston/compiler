// don't put using in ANY header files!
#include "Routines.cpp"
#include <vector>
#include "Expression.h"



struct TypeDecl
{

};

struct VarDecl
{

};



struct Block
{


};


struct Program
{
    std::vector<Constant> constants;
    std::vector<Var> vars;
    std::vector<Type> types;
//    TypeDecl typeDecl;
//    VarDecl varDel;
//    ProcedureDecl procedureDecl;
//    FunctionDecl functionDecl;
//    Block block;
};
