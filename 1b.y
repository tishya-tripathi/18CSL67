%{
#include "stdio.h"
#include "stdlib.h"
%}

%token NUM
%left '+' '-'
%left '*' '/'

%%
expr:	  e {printf("Result= %d\n", $1); return 0;} ;
e:	| e '+' e {$$=$1+$3;}
	| e '-' e {$$=$1-$3;}
	| e '*' e {$$=$1*$3;}
	| e '/' e {if($3==0) {printf("Cannot Divide by Zero\n"); exit(0);}
		   else {$$=$1/$3;} }
	| '('e')' {$$=$2;}
	| NUM	  {$$=$1;}
	;
%%	
	
main()	{
	printf("Enter expression to be evaluated\n");
	yyparse();
	printf("Valid Expression");
}

yyerror()	{
	printf("Invalid Expression\n");
	exit(0);
}