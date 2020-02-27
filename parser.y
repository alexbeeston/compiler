%{
#include <iostream>
#include <vector>
#include <map>
#include "symbol_table.hpp"
#include "global.h"

#include "constructs/expressions/Expression.h"
#include "constructs/expressions/StringLit.h"
#include "constructs/prelude/constants/Constant.h"
#include "constructs/Program.h"
#include "constructs/prelude/Prelude.h"

#include "constructs/expressions/CharLit.h"
#include "constructs/expressions/NumericLit.h"

#include "constructs/prelude/types/BaseType.h"
#include "constructs/prelude/types/TypeDeclItem.h"
#include "constructs/prelude/TypedList.h"

#include "constructs/routines/Routine.h"
#include "constructs/routines/Procedure.h"
#include "constructs/routines/Function.h"
#include "constructs/routines/ParameterSet.h"
#include "constructs/routines/Body.h"
#include "constructs/routines/Block.h"

#include "constructs/statements/Statement.h"
#include "constructs/statements/Assignment.h"
#include "constructs/statements/If.h"
#include "constructs/statements/While.h"
#include "constructs/statements/Repeat.h"
#include "constructs/statements/For.h"
#include "constructs/statements/Stop.h"
#include "constructs/statements/Return.h"
#include "constructs/statements/Read.h"
#include "constructs/statements/Write.h"

extern int yylex();
void yyerror(const char*);
Program* program;

%}

%union
{
float val;
int integer;
char* charPointer;
char character;
std::vector<char*>* charPointerVectorPointer;
struct Constant* constantPointer;
struct Expression* expressionPointer;
struct StringLit* stringLitPointer;
struct CharLit* charLitPointer;
std::vector<Constant*>* constantPointerVectorPointer;
struct Prelude* preludePointer;
struct NumericLit* numericLitPointer;

struct TypeDeclItem* typeDeclItemPointer;
struct BaseType* baseTypePointer;
std::vector<TypeDeclItem*>* typeDeclItemPointerVectorPointer;

struct TypedList* typedListPointer;
std::vector<TypedList*>* typedListPointerVectorPointer;

struct Routine* routinePointer;
std::vector<Routine*>* routinePointerVectorPointer;
struct Procedure* procedurePointer;
struct Function* functionPointer;
struct ParameterSet* parameterSetPointer;
std::vector<ParameterSet*>* parameterSetPointerVectorPointer;
struct Body* bodyPointer;
struct Block* blockPointer;

struct Statement* statementPointer;
std::vector<Statement*>* statementPointerVectorPointer;
struct Assignment* assignmentStatementPointer;
struct If* ifStatementPointer;
struct While* whileStatementPointer;
struct Repeat* repeatStatementPointer;
struct For* forStatementPointer;
struct Stop* stopStatementPointer;
struct Return* returnStatementPointer;
struct Read* readStatementPointer;
struct Write* writeStatementPointer;

}
%type <preludePointer> Prelude

%type <charPointer> IDENT
%type <val> LValue
%type <character> CHARLIT
%type <charPointer> STRLIT
%type <integer> DECINT
%type <charPointer> HEXINT
%type <charPointer> OCTINT
%type <charPointer> IdentExtra
%type <charPointerVectorPointer> IdentListExtraSet
%type <charPointerVectorPointer> IdentList

%type <expressionPointer> Expression
%type <constantPointer> Constant
%type <constantPointerVectorPointer> ConstantList
%type <constantPointerVectorPointer> ConstDecl
%type <numericLitPointer> NumericLiteral

%type <typeDeclItemPointerVectorPointer> TypeDecl
%type <typeDeclItemPointerVectorPointer> TypeList
%type <baseTypePointer> Type
%type <typeDeclItemPointer> TypeListItem
%type <baseTypePointer> SimpleType

%type <typedListPointer> TypedList
%type <typedListPointerVectorPointer> TypedLists
%type <typedListPointerVectorPointer> VarDecl

%type <routinePointer> RoutineDeclListItem
%type <routinePointerVectorPointer> RoutineDeclList
%type <procedurePointer> ProcedureDecl
%type <functionPointer> FunctionDecl
%type <parameterSetPointer> ParameterSet
%type <parameterSetPointer> ParameterSetListItem
%type <parameterSetPointerVectorPointer> FormalParameters
%type <parameterSetPointerVectorPointer> ParameterSetList
%type <integer> VarOrRef
%type <bodyPointer> Body
%type <blockPointer> Block

%type <statementPointer> Statement
%type <statementPointer> ExtraStatement
%type <statementPointerVectorPointer> ExtraStatementList
%type <statementPointerVectorPointer> StatementSequence

%type <assignmentStatementPointer> Assignment
%type <ifStatementPointer> IfStatement
%type <whileStatementPointer> WhileStatement
%type <repeatStatementPointer> RepeatStatement
%type <forStatementPointer> ForStatement
%type <stopStatementPointer> StopStatement
%type <returnStatementPointer> ReturnStatement
%type <readStatementPointer> ReadStatement
%type <writeStatementPointer> WriteStatement

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

Program : Prelude RoutineDeclList Block DOT { program = new Program($1, $2, $3); };
Prelude : ConstDecl TypeDecl VarDecl { $$ = new Prelude($1, $2, $3); };

RoutineDeclList : RoutineDeclList RoutineDeclListItem { $1->push_back($2); }
    | { $$ = new std::vector<Routine*>; };
    RoutineDeclListItem : ProcedureDecl | FunctionDecl ;
ProcedureDecl : PROCEDURE IDENT LPAREN FormalParameters RPAREN DONE FORWARD DONE { $$ = new Procedure($2, $4, NULL); }
    | PROCEDURE IDENT LPAREN FormalParameters RPAREN DONE Body DONE { $$ = new Procedure($2, $4, $7); };
    FormalParameters : ParameterSet ParameterSetList { $2->push_back($1); $$ = $2; } | { std::cout << "no formal paramters\n"; $$ = new std::vector<ParameterSet*>; } ;
            ParameterSet : VarOrRef IdentList COLON Type { $$ = new ParameterSet($1, $2, $4); };
                VarOrRef : VAR { $$ = 0; } |  REF { $$ = 1; } | { $$ = 0; } ;
            ParameterSetList : ParameterSetList ParameterSetListItem { $1->push_back($2); }
                | { $$ = new std::vector<ParameterSet*>; } ;
                ParameterSetListItem : DONE ParameterSet { $$ = $2; };
    Body : Prelude Block { $$ = new Body($1); };
FunctionDecl : FUNCTION IDENT LPAREN FormalParameters RPAREN COLON Type DONE FORWARD DONE { $$ = new Function($2, $4, NULL, $7); }
    | FUNCTION IDENT LPAREN FormalParameters RPAREN COLON Type DONE Body DONE { $$ = new Function($2, $4, $9, $7); }

ConstDecl : CONST ConstantList { $$ = $2;}
    | ;
ConstantList : Constant { $$ = new std::vector<Constant*>{$1}; }
    | ConstantList Constant { $1->push_back($2); }
    | ;

Constant : IDENT EQUAL Expression DONE { $$ = new Constant($1, $3); };
Expression : NumericLiteral
    | CHARLIT { $$ = new CharLit($1); }
    | STRLIT { $$ = new StringLit($1); }
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
    NumericLiteral : DECINT { $$ = new NumericLit($1); }
    | HEXINT
    | OCTINT;
TypeDecl : TYPE TypeList { $$ = $2; }
    | ;
TypeList : TypeList TypeListItem { $1->push_back($2); }
    | { $$ = new std::vector<TypeDeclItem*>; };
TypeListItem : IDENT EQUAL Type DONE { $$ = new TypeDeclItem($1, $3); }  ;
Type : SimpleType { $$ = new BaseType(); }
    | RecordType { $$ = new BaseType(); }
    | ArrayType  { $$ = new BaseType(); };
    SimpleType : IDENT
    RecordType : RECORD TypedLists END;
        TypedLists : TypedLists TypedList { $1->push_back($2); }
            | { $$ = new std::vector<TypedList*>; };
            TypedList: IdentList COLON Type DONE { $$ = new TypedList($1, $3); };
                IdentList : IDENT IdentListExtraSet { $2->push_back($1); $$ = $2;} ;
                    IdentListExtraSet : IdentListExtraSet IdentExtra { $1->push_back($2); }
                        | { $$ = new std::vector<char*>; };
                        IdentExtra : COMMA IDENT { $$ = $2; };
    ArrayType : ARRAY LBRACKET Expression COLON Expression RBRACKET OF Type ;

VarDecl : VAR TypedLists { $$ = $2; }
    | ;

Block: BEGIN_TOKEN StatementSequence END { $$ = new Block($2); };
StatementSequence : Statement ExtraStatementList { $2->insert($2->begin(), $1); $$ = $2; };
Statement : Assignment { $$ = new Assignment(); }
    | IfStatement { $$ = new If(); }
    | WhileStatement { $$ = new While(); }
    | RepeatStatement { $$ = new Repeat(); }
    | ForStatement { $$ = new For(); }
    | StopStatement { $$ = new Stop(); }
    | ReturnStatement { $$ = new Return(); }
    | ReadStatement { $$ = new Read(); }
    | WriteStatement { $$ = new Write(); }
    | ProcedureCall
    | { $$ = new Statement(); };
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
ExtraStatementList : ExtraStatementList ExtraStatement { $1->push_back($2); }
    | { $$ = new std::vector<Statement*>; };
ExtraStatement : DONE Statement { $$ = $2; };
%%

void yyerror(const char* msg)
{
  std::cerr << "Syntax Error. Could be near line " << lineNumber  << std::endl;
}

