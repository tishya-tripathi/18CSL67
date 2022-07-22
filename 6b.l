%{
        #include "stdio.h"
        #include "stdlib.h"
        #include "y.tab.h"
        extern int yylval;
%}

%%
[a-zA-Z0-9]+    {printf("ID is : %s \n", yytext);   return ID;}
[+ | - | * | / | = | < | >]     {printf("OP is : %s \n", yytext);   return OP;}
[0-9]+          {yylval=atoi(yytext); printf("DIGIT is : %s \n", yylval); return DIGIT;}
int|float|bool|char|void|if|else|for|while|do|return    {printf("KEYWORD is : %s", yytext); return KEYWORD;}
[\n]    ;
.       ;
%%