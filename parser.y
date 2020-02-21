%{
#include <iostream>
#include <vector>
#include <map>
#include "symbol_table.hpp"
#include "global.h"

#include "constructs/expression/Expression.h"
#include "constructs/expression/StringLit.h"
#include "constructs/Constant.h"
#include "constructs/Program.h"

extern int yylex();
void yyerror(const char*);
Program program;

%}

%union
{
float val;
char* charPointer;
char character;
int integer;
struct SimpleType* SimpleType_type;
struct Type* Type_type;
std::vector<char*>* vectorPointer;
struct Constant* constantPointer;
struct Expression* expressionPointer;
struct StringLit* stringLitPointer;
std::vector<Constant*>* constantPointerVectorPointer;
}

%type <charPointer> IDENT
%type <val> LValue
%type <expressionPointer> Expression
%type <charPointer> NumericLiteral
%type <charPointer> CHARLIT
%type <charPointer> STRLIT
%type <charPointer> DECINT
%type <charPointer> HEXINT
%type <charPointer> OCTINT
%type <charPointer> IdentExtra
%type <vectorPointer> IdentListExtraSet
%type <charPointer> Type
%type <charPointer> SimpleType
%type <constantPointer> Constant
%type <constantPointerVectorPointer> ConstantList

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

ConstDecl : CONST ConstantList { program.constants = $2; }
    | ;
ConstantList : Constant { $$ = new std::vector<Constant*>{$1}; }
    | ConstantList Constant { $1->push_back($2); }
    | ;

Constant : IDENT EQUAL Expression DONE { $$ = new Constant($1, $3); };
Expression : NumericLiteral
    | CHARLIT
    | STRLIT {$$ = new StringLit($1); }
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
    | SUCC LPAREN Expression RPAREN
    | LValue;
    MysterySet : Expression MysterySetList | ;
        MysterySetList : MysterySetList MysterySetListItem | ;
            MysterySetListItem : COMMA Expression;
    NumericLiteral : DECINT
    | HEXINT
    | OCTINT;
TypeDecl : TYPE TypeList | ;
TypeList : TypeList TypeListItem | ;
TypeListItem : IDENT EQUAL Type DONE { std::cout << "Type: " << $1 << " = " << $3 << std::endl; };
Type : SimpleType
    | RecordType {$$ = "Record Type"; }
    | ArrayType {$$ = "Array Type"; };
    SimpleType : IDENT ;
    RecordType : RECORD TypedLists END;
        TypedLists : TypedLists TypedList | ;
            TypedList: IdentList COLON Type DONE;
                IdentList : IDENT IdentListExtraSet;
                    IdentListExtraSet : IdentListExtraSet IdentExtra
                        | ;
                        IdentExtra : COMMA IDENT;
    ArrayType : ARRAY LBRACKET Expression COLON Expression RBRACKET OF Type ;

VarDecl : VAR TypedList TypedLists| ;

Block: BEGIN_TOKEN StatementSequence END
    | ;
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
%%

void yyerror(const char* msg)
{
  std::cerr << "Syntax Error. Could be near line " << lineNumber  << std::endl;
}

