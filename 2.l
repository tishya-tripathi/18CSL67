%{
#include "y.tab.h"
#include "stdlib.h"
%}

%%
a return A;
b return B;
. return yytext[0];
\n  return yytext[0];
%%