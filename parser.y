%{
#include <iostream>
#include <map>
#include "Root.h"
#include "symbol_table.hpp"

extern int yylex();
void yyerror(const char*);

Program program;
%}

%union
{
float val;
char* id;
}

%token ADD
%token SUB
%token MULT
%token DIV
%token OPEN
%token CLOSE
%token DONE
%token NUM
%token IDENT
%token EQUAL
%token LET
%token CONST
%token VAR

%type <val> NUM
%type <val> Factor
%type <val> Term
%type <id> ID

%%
ConstantList : ConstantList Constant;
    |;
Constant : NUM DONE { program.constants.push_back(Constant($1) ; } ;

/*
VarDecl: VAR VarList;
    |;

VarList: VarList Var;
    |;
Var: NUM DONE { program.constants.push_back(Constant($1) ; } ;

StatementList : StatementList Statement {}
              | ;
Statement : NUM DONE {std::cout << $1 << std::endl;} ;

Statement : Expression DONE {std::cout << $1 << std::endl;}
          | LET ID EQUAL Expression DONE{symbol_table.store($2,$4);delete($2);}
          | DONE{};
Expression : Expression ADD Term {$$ = $1 + $3;}
           | Expression SUB Term {$$ = $1 - $3;}
           | Term {$$ = $1;};

Term : Term MULT Factor { $$ = $1 * $3;}
     | Term Factor { $$ = $1 * $2;}
     | Term DIV Factor { $$ = $1 / $3;}
     | Factor {$$ = $1;}
     ;
Factor : OPEN Expression CLOSE {$$ = $2;}
       | NUMBER {$$ = $1;}
       | ID {$$ = symbol_table.lookup($1);delete($1);}
       ;
 */
%%

void yyerror(const char* msg)
{
  std::cerr << msg << std::endl;
}

