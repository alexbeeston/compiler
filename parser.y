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
%token TYPE
%token RECORD
%token END
%token COLON
%token COMMA
%token ARRAY
%token LBRACKET
%token RBRACKET
%token OF
%token BEGIN_TOKEN
%token WHILE
%token DO
%token ASSIGN
%token DOT
%token IF
%token THEN
%token ELSEIF

%type <val> NUM
%type <val> Expression

%%
Program : ConstDecl TypeDecl VarDecl Block;

ConstDecl : CONST Constant ConstantList | ;
ConstantList : ConstantList Constant | ;
Constant : IDENT EQUAL Expression DONE { program.constants.push_back(Constant($3)); } ;
Expression : NUM;

TypeDecl : TYPE TypeList | ;
TypeList : TypeList TypeListItem | ;
TypeListItem : IDENT EQUAL Type DONE ;
Type : SimpleType | RecordType | ArrayType;
    SimpleType : IDENT ;
    RecordType : RECORD RecordSet END;
        RecordSet : RecordSet Record | ;
            Record : IdentList COLON Type DONE;
                IdentList : IDENT IdentListExtraSet;
                    IdentListExtraSet : IdentListExtraSet IdentExtra | ;
                        IdentExtra : COMMA IDENT;
    ArrayType : ARRAY LBRACKET Expression COLON Expression RBRACKET OF Type ;

VarDecl : VAR Record RecordSet | ;

Block: BEGIN_TOKEN StatementSequence END | ;
StatementSequence : Statement ExtraStatementList;
Statement : Assignment
    | IfStatement
    | WhileStatement
    | ;
    Assignment : LValue ASSIGN Expression;
        LValue : IDENT LValueList;
        LValueList : LValueList LValueItem | ;
        LValueItem : DOT IDENT
            | LBRACKET Expression RBRACKET;
    IfStatement : IF Expression THEN StatementSequence ElseIfList END;
        ElseIfList : ElseIfList ElseIfListItem | ;
            ElseIfListItem : ELSEIF Expression THEN StatementSequence;
    WhileStatement : WHILE Expression DO StatementSequence END;


ExtraStatementList : ExtraStatementList ExtraStatement | ;
ExtraStatement : DONE Statement;





/*


        ElseIfList : ElseIfList ElseIfListItem | ;
        ElseIfListItem : ELSEIF Expression THEN StatementSequence;
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

