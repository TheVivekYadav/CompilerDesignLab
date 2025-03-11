%{
#include <stdio.h>
%}

%token IDENTIFIER

%%

stmt: IDENTIFIER { printf("Valid variable name: %s\n", yytext); }
    ;

%%

int main() {
    printf("Enter a variable name:\n");
    yyparse();
    return 0;
}

void yyerror(char *s) {
    printf("Error: %s\n", s);
}

