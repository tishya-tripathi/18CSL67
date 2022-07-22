%{
    #include "stdio.h"
    #include "stdlib.h"
    int id=0,op=0,id=0,key=0;    
%}

%token KEYWORD ID DIGIT OP

%%
input: KEYWORD input {key++;} | ID input {id++;} | DIGIT input {dig++;} | OP input {op++;} | 
       KEYWORD {key++;} | ID {id++;} | DIGIT {id++;} | OP {id++;}
%%

main()
{
    FILE *fp = fopen("fp.c");
    yyin = fp;
    do {
        yyparse();
    }while(!feof(yyin));
}

yyerror()
{
    printf("Parse ERROR!\n");   exit(-1);
}