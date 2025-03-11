%{
#include "y.tab.h"
%}

%%

[0-9]+     { yylval = atoi(yytext); return NUMBER; }
[\+\-\*/]  { return yytext[0]; }
\n         { return 0; }  // End of expression
[ \t]      { /* Ignore spaces and tabs */ }
.          { printf("Invalid character: %s\n", yytext); }

%%

