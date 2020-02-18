%{
#include <iostream>
#include <map>
#include "Types.h"
#include "Program.h"
#include "symbol_table.hpp"

extern int yylex();
void yyerror(const char*);

Program program;
%}

%union
{
float val;
char* string;
char character;
int integer;
struct SimpleType* SimpleType_type;
struct Type* Type_type;
}

%token ADD
%token SUB
%token MULT
%token DIV
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
%token RETURN_TOKEN
%token PROCEDURE
%token FORWARD
%token REF
%token FUNCTION

%token WHILE
%token DO
%token FOR
%token TO
%token DOWNTO
%token STOP

%token ASSIGN
%token DOT
%token IF
%token THEN
%token ELSEIF
%token ELSE
%token REPEAT
%token UNTIL
%token READ
%token WRITE


%token TILDA
%token GREATER_THAN_OR_EQUAL
%token LESS_THAN_OR_EQUAL
%token LESS_THAN
%token GREATER_THAN
%token MOD
%token NOTEQUAL
%token OR
%token AND
%token NEGATION
%token CHR
%token ORD
%token PRED
%token SUCC
%token LPAREN
%token RPAREN

%token CHARLIT
%token STRLIT
%token HEXINT
%token OCTINT
%token DECINT


%type <string> IDENT
%type <val> LValue
%type <val> Expression
%type <character> CHARLIT
%type <string> STRLIT
%type <integer> DECINT
%type <SimpleType_type> SimpleType
%type <SimpleType_type> Type

%%
Program : Prelude RoutineDeclList Block DOT;
Prelude : ConstDecl TypeDecl VarDecl;

RoutineDeclList : RoutineDeclList RoutineDeclListItem | ;
    RoutineDeclListItem : ProcedureDecl | FunctionDecl;
ProcedureDecl : PROCEDURE IDENT LPAREN FormalParameters RPAREN DONE FORWARD DONE
    | PROCEDURE IDENT LPAREN FormalParameters RPAREN DONE Body DONE;
    FormalParameters : ParameterSet ParameterSetList | ;
            ParameterSet : VarOrRef IdentList COLON Type;
                VarOrRef : VAR | REF | ;
            ParameterSetList : ParameterSetList ParameterSetListItem | ;
                ParameterSetListItem : DONE ParameterSet;
    Body : Prelude Block;
FunctionDecl : FUNCTION IDENT LPAREN FormalParameters RPAREN COLON Type DONE FORWARD DONE
    | FUNCTION IDENT LPAREN FormalParameters RPAREN COLON Type DONE Body DONE;

ConstDecl : CONST Constant ConstantList | ;
ConstantList : ConstantList Constant | ;
Constant : IDENT EQUAL Expression DONE { std::cout << "got an expression constant: " << $3 << std::endl; }
    | IDENT EQUAL CHARLIT DONE {std::cout<< "got a char: " << $3 << std::endl; }
    | IDENT EQUAL STRLIT DONE { std::cout << "got a string:" << $3 << std::endl; }
    | IDENT EQUAL DECINT DONE { std::cout << "dec const" << $3 << std::endl;}
    | IDENT EQUAL IDENT DONE {std::cout << "const identifier: " << $3 << std::endl;} ;
Expression : LValue
    | DECINT
    | LPAREN Expression RPAREN
    | SUB Expression
    | Expression MULT Expression
    | Expression DIV Expression
    | Expression MOD Expression
    | Expression ADD Expression
    | Expression SUB Expression
    | Expression EQUAL Expression
    | Expression NOTEQUAL Expression
    | Expression LESS_THAN Expression
    | Expression LESS_THAN_OR_EQUAL Expression
    | Expression GREATER_THAN Expression
    | Expression GREATER_THAN_OR_EQUAL Expression
    | Expression AND Expression
    | NEGATION Expression
    | Expression OR Expression
    | IDENT LPAREN MysterySet RPAREN
    | CHR LPAREN Expression RPAREN
    | ORD LPAREN Expression RPAREN
    | PRED LPAREN Expression RPAREN
    | SUCC LPAREN Expression RPAREN;
    MysterySet : Expression MysterySetList | ;
        MysterySetList : MysterySetList MysterySetListItem | ;
            MysterySetListItem : COMMA Expression;

TypeDecl : TYPE TypeList | ;
TypeList : TypeList TypeListItem | ;
TypeListItem : IDENT EQUAL Type DONE { program.types.push_back($3); };
Type : SimpleType { $$ = $1;} | RecordType | ArrayType;
    SimpleType : IDENT { $$ = new SimpleType($1); };
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
    | RepeatStatement
    | ForStatement
    | StopStatement
    | ReturnStatement
    | ReadStatement
    | WriteStatement
    | ProcedureCall
    | ;
    Assignment : LValue ASSIGN Expression;
        LValue : IDENT LValueList;
        LValueList : LValueList LValueItem | ;
        LValueItem : DOT IDENT
            | LBRACKET Expression RBRACKET;
    IfStatement : IF Expression THEN StatementSequence ElseIfList Else END;
        ElseIfList : ElseIfList ElseIfListItem | ;
            ElseIfListItem : ELSEIF Expression THEN StatementSequence;
        Else : ELSE StatementSequence | ;
    WhileStatement : WHILE Expression DO StatementSequence END;
    RepeatStatement : REPEAT StatementSequence UNTIL Expression;
    ForStatement : FOR IDENT ASSIGN Expression Location Expression DO StatementSequence END;
        Location : TO | DOWNTO;
    StopStatement : STOP;
    ReturnStatement : RETURN_TOKEN | RETURN_TOKEN Expression;
    ReadStatement : READ LPAREN LValue CommaExpressionList RPAREN;
        CommaExpressionList: CommaExpressionList CommaExpressionListItem | ;
            CommaExpressionListItem: COMMA Expression;
    WriteStatement : WRITE LPAREN Expression CommaExpressionList RPAREN;
    ProcedureCall : IDENT LPAREN ProcedureParams RPAREN;
        ProcedureParams : Expression CommaExpressionList | ;


ExtraStatementList : ExtraStatementList ExtraStatement | ;
ExtraStatement : DONE Statement;





/*

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

