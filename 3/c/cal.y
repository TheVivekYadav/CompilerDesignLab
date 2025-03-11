%{
#include <stdio.h>
#include <stdlib.h>
%}

%token NUMBER
%left '+' '-'
%left '*' '/'
%right UMINUS

%%

expr: expr '+' expr  { printf("%d\n", $1 + $3); }
    | expr '-' expr  { printf("%d\n", $1 - $3); }
    | expr '*' expr  { printf("%d\n", $1 * $3); }
    | expr '/' expr  { if ($3 == 0) { printf("Error: Division by zero\n"); exit(1); } else printf("%d\n", $1 / $3); }
    | '-' expr %prec UMINUS { $$ = -$2; }
    | '(' expr ')'  { $$ = $2; }
    | NUMBER       { $$ = $1; }
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

