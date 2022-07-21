%{
#include "stdio.h"
%}

%%
"//".* ;
"/*"(.|\n)+"*/" ;
%%

main()
{
    yyin = fopen("abc.c", "r");
    yyout = fopen("xyz.c", "w");
    yylex();
    return 0;
}