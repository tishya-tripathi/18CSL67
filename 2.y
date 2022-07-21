%{
#include "stdlib.h"
#include "stdio.h"
%}

%token A B

%%
str:	s'\n' {printf("Valid String\n"); exit(0);} ;
s:	x B	;
x:	A x | A	; 	
%%

main()
{
	printf("Enter input\n");
	yyparse();
}

yyerror()
{
	printf("Invalid String\n");
	exit(0);
}