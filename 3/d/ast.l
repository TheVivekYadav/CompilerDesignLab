%{
#include "y.tab.h"
#include <stdlib.h>
%}

%%

[0-9]+  { yylval = atoi(yytext); return NUMBER; }
[\+\-\*/]  { return yytext[0]; }
"("     { return '('; }
")"     { return ')'; }
\n      { return 0; }  // End of input
[ \t]   { /* Ignore spaces and tabs */ }

%%

