%{
#include <stdio.h>
#include "y.tab.h"
%}

DIGIT [0-9]+
ID [a-zA-Z_][a-zA-Z0-9_]*
WHITESPACE [ \t\n]+

%%
{DIGIT}     { printf("%s is a number\n", yytext); }
{ID}        { printf("%s is an identifier\n", yytext); }
[+\-*/=;]   { printf("%s is an operator or special symbol\n", yytext); }
{WHITESPACE} { /* Ignore whitespace */ }
.           { printf("%s is an unknown character\n", yytext); }
%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 0;
}

