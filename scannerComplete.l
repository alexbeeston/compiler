%{
#include <cstdlib>
#include "parser.hpp"
%}
%option noyywrap
%%
\$.*\n {}

"[^"]*" {return string;}
'\\n' {yylval = '\n'; return CHAR;}
'\\r' {yylval = '\r'; return CHAR;}
'\\b' {yylval = '\b'; return CHAR;}
'\\t' {yylval = '\t'; return CHAR;}
'\\f' {yylval = '\f'; return CHAR;}
'\\\\'  {return ERROR;}
'\\.' {yylval = yytext[2]; return CHAR;}
'.' {yylval = yytext[1]; return CHAR;}

array|ARRAY {return ARRAY;}
else|ELSE {return ELSE;}
if|IF {return IF;}
record|RECORD {return RECORD;}
then|THEN {return THEN;}
write|WRITE {return WRITE;}
begin|BEGIN {return BEGIN;}
elseif|ELSEIF {return ELSEIF;}
of|OF {return OF;}
ref|REF {return REF;}
to|TO {return TO;}
chr|CHR {return CHR;}
end|END {return END;}
ord|ORD {return ORD;}
repeat|REPEAT {return REPEAT;}
type|TYPE {return TYPE;}
const|CONST {return CONST;}
for|FOR {return FOR;}
pred|PRED {return PRED;}
return|RETURN {return RETURN;}
until|UNTIL {return UNTIL;}
do|DO {return DO;}
forward|FORWARD {return FORWARD;}
procedure|PROCEDURE {return PROCEDURE;}
stop|STOP {return STOP;}
var|VAR {return VAR;}
downto|DOWNTO {return DOWNTO;}
function|FUNCTION {return FUNCTION;}
read|READ {return READ;}
succ|SUCC {return SUCC;}
while|WHILE {return WHILE;}

[a-zA-Z][a-zA-Z0-9_]* {return id;}
0[0-7]* {return octalInt;}
0x[0-9a-fA-F]* {return hexadecimalInt;}
[1-9][0-9]* {return decimalInt;}

\+ {return add;}
- {return subtract;}
\* {return multiply;}
/ {return divide;}
& {return and;}
\| {return or;}
~ {return idk;}
= {return assignment;}
<> {return idk;}
< {return lessThan;}
> {return greaterThan;}
<= {return lessThanOrEqualTo;}
>= {return greaterThanOrEqualTo;}
\. {return dot;}
, {return delimiter;}
: {return scope;}
; {return statement;}
\( {return openParen;}
\) {return closeParen;}
\[ {return openBracket;}
\] {return closeBracket;}
:= {return idk;}
% {return modulus;}

. {return unknown;}
%%
