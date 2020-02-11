// don't put using in ANY header files!
#include "Routines.cpp";


struct ConstantDecl
{

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
    TypeDecl typeDecl;
    VarDecl varDel;
    ProcedureDecl procedureDecl;
    FunctionDecl functionDecl;
    Block block;

    int testing1 = 1000;
    int testing2 = 2000;
    int testing3;
};
