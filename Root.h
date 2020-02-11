// don't put using in ANY header files!
#include "Routines.cpp";
#include <vector>
#include "Expression.h"

struct ConstantDecl
{
    std::vector<Constant> constants;
};

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
    ConstantDecl constDecl;
//    TypeDecl typeDecl;
//    VarDecl varDel;
//    ProcedureDecl procedureDecl;
//    FunctionDecl functionDecl;
//    Block block;
};
