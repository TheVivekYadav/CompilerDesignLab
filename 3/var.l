%{
#include "y.tab.h"
%}

%%

[a-zA-Z][a-zA-Z0-9]*  { return IDENTIFIER; }
\n                    { return 0; }  // End of input
[ \t]                 { /* Ignore spaces and tabs */ }
.                     { printf("Invalid character: %s\n", yytext); }

%%

