%{
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "global.h"

#include "expressions/Expression.h"
#include "miscellaneous/Constant.h"
#include "routines/Program.h"

#include "miscellaneous/LValue.h"
#include "miscellaneous/LValueBase.h"
#include "miscellaneous/Prelude.h"
#include "miscellaneous/TypedList.h"

#include "types/BaseType.h"
#include "types/SimpleType.h"
#include "types/ArrayType.h"
#include "types/RecordType.h"
#include "types/DeclaredType.h"

#include "routines/Routine.h"
#include "routines/Procedure.h"
#include "routines/Function.h"
#include "routines/ParameterSet.h"
#include "routines/Body.h"
#include "routines/Block.h"

#include "statements/Statement.h"
#include "statements/Assignment.h"
#include "statements/If.h"
#include "statements/ConditionalSequence.h"
#include "statements/While.h"
#include "statements/Repeat.h"
#include "statements/For.h"
#include "statements/Stop.h"
#include "statements/Return.h"
#include "statements/Read.h"
#include "statements/Write.h"
#include "statements/ProcedureCall.h"
#include "statements/NullStatement.h"

#include "expressions/Literal.h"
#include "expressions/Or.h"
#include "expressions/And.h"
#include "expressions/NotEqual.h"
#include "expressions/LessThanEqual.h"
#include "expressions/GreaterThanEqual.h"
#include "expressions/GreaterThan.h"
#include "expressions/LessThan.h"
#include "expressions/Add.h"
#include "expressions/FunctionCall.h"
#include "expressions/Sub.h"
#include "expressions/Multiply.h"
#include "expressions/Divide.h"
#include "expressions/Mod.h"
#include "expressions/Negate.h"
#include "expressions/Negative.h"
#include "expressions/ParenExpression.h"
#include "expressions/ChrFunc.h"
#include "expressions/OrdFunc.h"
#include "expressions/PredFunc.h"
#include "expressions/SuccFunc.h"
#include "expressions/LValueExpression.h"
#include "expressions/Equal.h"


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

struct LValueBase* lValueBasePointer;
struct LValue* lValuePointer;
std::vector<LValue*>* lValuePointerVectorPointer;
std::vector<LValueBase*>* lValueBasePointerVectorPointer;

std::vector<char*>* charPointerVectorPointer;
struct Constant* constantPointer;

struct Expression* expressionPointer;
std::vector<Expression*>* expressionPointerVectorPointer;

std::vector<Constant*>* constantPointerVectorPointer;
struct Prelude* preludePointer;
struct Literal* literalPointer;

struct DeclaredType* declaredTypePointer;
struct BaseType* baseTypePointer;
struct SimpleType* simpleTypePointer;
struct ArrayType* arrayTypePointer;
struct RecordType* recordTypePointer;
std::vector<DeclaredType*>* declaredTypePointerVectorPointer;

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
struct ConditionalSequence* conditionalSequencePointer;
std::vector<ConditionalSequence*>* conditionalSequencePointerVectorPointer;
struct While* whileStatementPointer;
struct Repeat* repeatStatementPointer;
struct For* forStatementPointer;
struct Stop* stopStatementPointer;
struct Return* returnStatementPointer;
struct Read* readStatementPointer;
struct Write* writeStatementPointer;
struct ProcedureCall* procedureCallStatementPointer;
}
%type <preludePointer> Prelude

%type <lValuePointer> LValue
%type <lValueBasePointerVectorPointer>  LValueBaseList
%type <lValueBasePointer> LValueBaseItem

%type <lValuePointerVectorPointer> LValueCommaList
%type <lValuePointer> LValueCommaListItem

%type <charPointer> IDENT
%type <character> CHARLIT
%type <charPointer> STRLIT
%type <integer> DECINT
%type <charPointer> HEXINT
%type <charPointer> OCTINT
%type <charPointer> IdentExtra
%type <charPointerVectorPointer> IdentListExtraSet
%type <charPointerVectorPointer> IdentList

%type <expressionPointer> Expression
%type <expressionPointer> CommaExpression
%type <expressionPointerVectorPointer> CommaExpressionList
%type <expressionPointerVectorPointer> ProcedureParams
%type <constantPointer> Constant
%type <constantPointerVectorPointer> ConstantList
%type <constantPointerVectorPointer> ConstDecl
%type <literalPointer> NumericLiteral

%type <declaredTypePointerVectorPointer> TypeDecl
%type <declaredTypePointerVectorPointer> TypeList
%type <declaredTypePointer> TypeListItem

%type <baseTypePointer> Type
%type <simpleTypePointer> SimpleType
%type <arrayTypePointer> ArrayType
%type <recordTypePointer> RecordType

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
%type <conditionalSequencePointer> ConditionalSequence
%type <conditionalSequencePointerVectorPointer> ConditionalSequenceList
%type <statementPointerVectorPointer> Else
%type <whileStatementPointer> WhileStatement
%type <repeatStatementPointer> RepeatStatement
%type <forStatementPointer> ForStatement
%type <integer> Location
%type <stopStatementPointer> StopStatement
%type <returnStatementPointer> ReturnStatement
%type <readStatementPointer> ReadStatement
%type <writeStatementPointer> WriteStatement
%type <procedureCallStatementPointer> ProcedureCallStatement

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
%token ZERO

%left NEGATION ADD
%nonassoc EQUAL NOTEQUAL
%left MULT DIV MOD


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
    Body : Prelude Block { $$ = new Body($1, $2);   };
FunctionDecl : FUNCTION IDENT LPAREN FormalParameters RPAREN COLON Type DONE FORWARD DONE { $$ = new Function($2, $4, nullptr, $7); }
    | FUNCTION IDENT LPAREN FormalParameters RPAREN COLON Type DONE Body DONE { $$ = new Function($2, $4, $9, $7); }

ConstDecl : CONST Constant ConstantList { $3->insert($3->begin(), $2);  $$ = $3;}
    | { $$ = new std::vector<Constant*>; };
ConstantList : ConstantList Constant { $1->push_back($2); }
    | { $$ = new std::vector<Constant*>; };

Constant : IDENT EQUAL Expression DONE { $$ = new Constant($1, $3); };
Expression : NumericLiteral
    | CHARLIT { $$ = new Literal($1); }
    | STRLIT { $$ = new Literal($1); }
    | LPAREN Expression RPAREN { $$ = new ParenExpression($2); }
    | SUB Expression { $$ = new Negative($2); }
    | Expression MULT Expression { $$ = new Multiply($1, $3); }
    | Expression DIV Expression { $$ = new Divide($1, $3); }
    | Expression MOD Expression { $$ = new Mod($1, $3); }
    | Expression ADD Expression { $$ = new Add($1, $3); }
    | Expression SUB Expression { $$ = new Sub($1, $3); }
    | Expression EQUAL Expression { $$ = new Equal($1, $3); }
    | Expression NOTEQUAL Expression { $$ = new NotEqual($1, $3); }
    | Expression LESS_THAN Expression { $$ = new LessThan($1, $3); }
    | Expression LESS_THAN_OR_EQUAL Expression { $$ = new LessThanEqual($1, $3); }
    | Expression GREATER_THAN Expression { $$ = new GreaterThan($1, $3); }
    | Expression GREATER_THAN_OR_EQUAL Expression { $$ = new GreaterThanEqual($1, $3); }
    | Expression AND Expression { $$ = new And($1, $3); }
    | NEGATION Expression { $$ = new Negate($2); }
    | Expression OR Expression { $$ = new Or($1, $3); }
    | IDENT LPAREN ProcedureParams RPAREN { $$ = new FunctionCall($1, $3); }
    | CHR LPAREN Expression RPAREN { $$ = new ChrFunc($3); }
    | ORD LPAREN Expression RPAREN { $$ = new OrdFunc($3); }
    | PRED LPAREN Expression RPAREN { $$ = new PredFunc($3); }
    | SUCC LPAREN Expression RPAREN { $$ = new SuccFunc($3); }
    | LValue { $$ = new LValueExpression($1); };

    NumericLiteral : DECINT { $$ = new Literal($1); }
    | HEXINT { $$ = new Literal($1); }
    | OCTINT { $$ = new Literal($1); }
    | ZERO { $$ = new Literal(0); };
TypeDecl : TYPE TypeListItem TypeList { $3->insert($3->begin(), $2); $$ = $3; }
    | { $$ = new std::vector<DeclaredType*>; };
TypeList : TypeList TypeListItem { $1->push_back($2); }
    | { $$ = new std::vector<DeclaredType*>; };
TypeListItem : IDENT EQUAL Type DONE { $$ = new DeclaredType($1, $3); };
Type : SimpleType
    | RecordType
    | ArrayType
    SimpleType : IDENT { $$ = new SimpleType(new std::string($1)); };
    RecordType : RECORD TypedLists END { $$ = new RecordType($2); };
        TypedLists : TypedLists TypedList { $1->push_back($2); }
            | { $$ = new std::vector<TypedList*>; };
            TypedList: IdentList COLON Type DONE { $$ = new TypedList($1, $3); };
                IdentList : IDENT IdentListExtraSet { $2->insert($2->begin(), $1); $$ = $2;} ;
                    IdentListExtraSet : IdentListExtraSet IdentExtra { $1->push_back($2); }
                        | { $$ = new std::vector<char*>; };
                        IdentExtra : COMMA IDENT { $$ = $2; };
    ArrayType : ARRAY LBRACKET Expression COLON Expression RBRACKET OF Type { $$ = new ArrayType($3, $5, $8); };

VarDecl : VAR TypedList TypedLists { $3->insert($3->begin(), $2); $$ = $3; }
    | { $$ = new std::vector<TypedList*>; };

Block: BEGIN_TOKEN StatementSequence END { $$ = new Block($2); };
StatementSequence : Statement ExtraStatementList { $2->insert($2->begin(), $1); $$ = $2; };
Statement : Assignment
    | IfStatement
    | WhileStatement
    | RepeatStatement
    | ForStatement
    | StopStatement { $$ = new Stop(); }
    | ReturnStatement
    | ReadStatement
    | WriteStatement
    | ProcedureCallStatement
    | { $$ = new NullStatement(); };
    Assignment : LValue ASSIGN Expression { $$ = new Assignment($1, $3); };
        LValue : IDENT LValueBaseList { $2->insert($2->begin(), new LValueBase($1)); $$ = new LValue($2); };
        LValueBaseList : LValueBaseList LValueBaseItem { $1->push_back($2); }
            | { $$ = new std::vector<LValueBase*>; };
        LValueBaseItem : DOT IDENT { $$ = new LValueBase($2); }
            | LBRACKET Expression RBRACKET { $$ = new LValueBase($2); };
    IfStatement : IF Expression THEN StatementSequence ConditionalSequenceList Else END { $$ = new If(new ConditionalSequence($2, $4), $5, $6); };
        ConditionalSequenceList : ConditionalSequenceList ConditionalSequence { $1->push_back($2); }
            | { $$ = new std::vector<ConditionalSequence*>; };
            ConditionalSequence: ELSEIF Expression THEN StatementSequence { $$ = new ConditionalSequence($2, $4); };
        Else : ELSE StatementSequence { $$ = $2; }
            | { $$ = nullptr;} ;
    WhileStatement : WHILE Expression DO StatementSequence END { $$ = new While($2, $4); };
    RepeatStatement : REPEAT StatementSequence UNTIL Expression { $$ = new Repeat($4, $2); };
    ForStatement : FOR IDENT ASSIGN Expression Location Expression DO StatementSequence END { $$ = new For($2, $4, $5, $6, $8); };
        Location : TO { $$ = 1;} | DOWNTO { $$ = 0; };
    StopStatement : STOP;
    ReturnStatement : RETURN_TOKEN { $$ = new Return(); } | RETURN_TOKEN Expression { $$ = new Return($2); };
    ReadStatement : READ LPAREN LValue LValueCommaList RPAREN { $$ = new Read($3, $4); };
        LValueCommaList: LValueCommaList LValueCommaListItem { $1->push_back($2); }
            | { $$ = new std::vector<LValue*>; };
            LValueCommaListItem : COMMA LValue { $$ = $2; };
    WriteStatement : WRITE LPAREN Expression CommaExpressionList RPAREN { $$ = new Write($3, $4); };
    CommaExpressionList : CommaExpressionList CommaExpression { $1->push_back($2); }
        | { $$ = new std::vector<Expression*>; };
        CommaExpression : COMMA Expression { $$ = $2; };
    ProcedureCallStatement : IDENT LPAREN ProcedureParams RPAREN { $$ = new ProcedureCall($1, $3); };
        ProcedureParams : Expression CommaExpressionList { $2->insert($2->begin(), $1); $$ = $2; }
            | { $$ = new std::vector<Expression*>; };

ExtraStatementList : ExtraStatementList ExtraStatement { $1->push_back($2); }
    | { $$ = new std::vector<Statement*>; };
ExtraStatement : DONE Statement { $$ = $2; };
%%

void yyerror(const char* msg)
{
  std::cerr << "Syntax Error. Could be near line " << lineNumber  << std::endl;
}

