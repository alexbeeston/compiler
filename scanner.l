%{
#include <cstdlib>
#include <iostream>
#include <vector>
#include "parser.hpp"
#include "global.h"
#include "constructs/expression/Expression.h"
#include "constructs/Constant.h"
#include "constructs/expression/CharLit.h"


int lineNumber = 0;
%}

%option noyywrap

%%
"\n" { ++lineNumber; }

const|CONST {return CONST;}
var|VAR {return VAR;}
type|TYPE {return TYPE;}
end|END {return END;}
record|RECORD {return RECORD;}
array|ARRAY {return ARRAY;}
of|OF {return OF;}
begin|BEGIN {return BEGIN_TOKEN;}
while|WHILE {return WHILE;}
do|DO {return DO;}
if|IF {return IF;}
elseif|ELSEIF {return ELSEIF;}
then|THEN {return THEN;}
else|ELSE {return ELSE;}
ord|ORD {return ORD;}
chr|CHR {return CHR;}
pred|PRED {return PRED;}
succ|SUCC {return SUCC;}
repeat|REPEAT {return REPEAT;}
until|UNTIL {return UNTIL;}
for|FOR {return FOR;}
to|TO {return TO;}
downto|DOWNTO {return DOWNTO;}
stop|STOP {return STOP;}
return|RETURN {return RETURN_TOKEN;}
read|READ {return READ;}
write|WRITE {return WRITE;}
procedure|PROCEDURE {return PROCEDURE;}
forward|FORWARD {return FORWARD;}
ref|REF {return REF;}
function|FUNCTION {return FUNCTION;}

'\\n' {yylval.character = '\n'; return CHARLIT;}
'\\r' {yylval.character = '\r'; return CHARLIT;}
'\\b' {yylval.character = '\b'; return CHARLIT;}
'\\t' {yylval.character = '\t'; return CHARLIT;}
'\\f' {yylval.character = '\f'; return CHARLIT;}
'\\.' {yylval.character = yytext[2]; return CHARLIT;}
'.' {yylval.character = yytext[1]; return CHARLIT;}
0[0-7]* {return OCTINT;}
0x[0-9a-fA-F]* {return HEXINT;}
[1-9][0-9]* {yylval.charPointer = strdup(yytext); return DECINT;}
\"[^\"]*\"  {yylval.charPointer = strdup(yytext); return STRLIT;}
[a-zA-Z][a-zA-Z0-9_]* {yylval.charPointer = strdup(yytext); return IDENT;}

"<>" {return NOTEQUAL;}
">=" {return GREATER_THAN_OR_EQUAL;}
"<=" {return LESS_THAN_OR_EQUAL;}
"<" {return LESS_THAN;}
">" {return GREATER_THAN;}
"%" {return MOD;}
"+" {return ADD;}
"-" {return SUB;}
"*" {return MULT;}
"/" {return DIV;}
"~" {return NEGATION;}
"[" {return LBRACKET;}
"]" {return RBRACKET;}
"&" {return AND;}
"|" {return OR;}
"(" {return LPAREN;}
")" {return RPAREN;}
":" {return COLON;}
";" {return DONE;}
"=" {return EQUAL;}
"," {return COMMA;}
":=" {return ASSIGN;}
"." {return DOT;}

 /*
[a-z] {yylval.id = strdup(yytext);return ID;}
_[a-zA-Z]+ {yylval.id = strdup(yytext+1);return ID;}
[ \t] {}
[0-9]*\.[0-9]* {yylval.val = atof(yytext);return NUMBER;}
[0-9]+ {yylval.val = atof(yytext);return NUMBER;}
 */

%%
