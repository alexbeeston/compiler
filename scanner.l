%{
#include <cstdlib>
#include <iostream>
#include "parser.hpp"
%}
%option noyywrap
%%

"comment" {;}

"const" {return CONST;}
"var" {return VAR;}
"type" {return TYPE;}
"end" {return END;}
"record" {return RECORD;}
"array" {return ARRAY;}
"of" {return OF;}
"begin" {return BEGIN_TOKEN;}
"while" {return WHILE;}
"do" {return DO;}
"if" {return IF;}
"elseif" {return ELSEIF;}
"then" {return THEN;}
"else" {return ELSE;}
"ord" {return ORD;}
"chr" {return CHR;}
"pred" {return PRED;}
"succ" {return SUCC;}
"repeat" {return REPEAT;}
"until" {return UNTIL;}
"for" {return FOR;}
"to" {return TO;}
"downto" {return DOWNTO;}
"stop" {return STOP;}
"return" {return RETURN_TOKEN;}
"read" {return READ;}
"write" {return WRITE;}
"procedure" {return PROCEDURE;}
"forward" {return FORWARD;}
"ref" {return REF;}
"function" {return FUNCTION;}

'\\n' {yylval.character = '\n'; return CHARCONST;}
'\\r' {yylval.character = '\r'; return CHARCONST;}
'\\b' {yylval.character = '\b'; return CHARCONST;}
'\\t' {yylval.character = '\t'; return CHARCONST;}
'\\f' {yylval.character = '\f'; return CHARCONST;}
'\\.' {yylval.character = yytext[2]; return CHARCONST;}
'.' {yylval.character = yytext[1]; return CHARCONST;}
0[0-7]* {return OCTCONST;}
0x[0-9a-fA-F]* {return HEXCONST;}
[1-9][0-9]* {yylval.string = strdup(yytext); return DECCONST;}

[a-zA-Z][a-zA-Z0-9_]* {yylval.string = strdup(yytext); return IDENT;}

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
