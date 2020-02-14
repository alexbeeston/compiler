%{
#include <cstdlib>
#include <iostream>
#include "parser.hpp"
%}
%option noyywrap
%%
"const" {return CONST;}
"var" {return VAR;}
"type" {return TYPE;}
"end" {return END;}
"record" {return RECORD;}
"array" {return ARRAY;}
"of" {return OF;}
"[" {return LBRACKET;}
"]" {return RBRACKET;};
"begin" {return BEGIN_TOKEN;}
"while" {return WHILE;}
"do" {return DO;}
"if" {return IF;}
"elseif" {return ELSEIF;}
"then" {return THEN;}
"else" {return ELSE;}

":" {return COLON;}
";" {return DONE;}
"=" {return EQUAL;}
"," {return COMMA;}
":=" {return ASSIGN;}
"." {return DOT;}

"stuff" {yylval.id = strdup(yytext); return RECORD;}


[0-9]+ {yylval.val = atof(yytext); return NUM;}
[a-zA-Z][a-zA-Z0-9_]* {yylval.id = strdup(yytext); return IDENT;}





 /*
"+" {return ADD;}
"-" {return SUB;}
"*" {return MULT;}
"/" {return DIV;}
"(" {return OPEN;}
")" {return CLOSE;}
"\n" {return DONE;}
";" {return DONE;}
"=" {return EQUAL;}
"==" {return EQUAL;}
":=" {return EQUAL;}
[a-z] {yylval.id = strdup(yytext);return ID;}
_[a-zA-Z]+ {yylval.id = strdup(yytext+1);return ID;}
[ \t] {}
[0-9]*\.[0-9]* {yylval.val = atof(yytext);return NUMBER;}
[0-9]+ {yylval.val = atof(yytext);return NUMBER;}
 */

%%
