%{
#include <stdio.h>
#include <stdlib.h>
%}

%token NUMBER
%left '+' '-'
%left '*' '/'

%%

expr: expr '+' expr { printf("Addition\n"); }
    | expr '-' expr { printf("Subtraction\n"); }
    | expr '*' expr { printf("Multiplication\n"); }
    | expr '/' expr { printf("Division\n"); }
    | NUMBER        { printf("Number: %d\n", $1); }
    ;

%%

int main() {
    printf("Enter an arithmetic expression:\n");
    yyparse();
    return 0;
}

void yyerror(char *s) {
    printf("Error: %s\n", s);
}

