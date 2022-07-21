%{
	int a[]={0,0,0,0};
	int opnd=0, i=0, valid=1;
%}

%x OPER

%%

[a-zA-Z0-9]+ {BEGIN OPER; opnd++;}
<OPER>"+"   {if(valid) {i=0; valid=0;}	else ext();}
<OPER>"-"   {if(valid) {i=1; valid=0;}	else ext();}
<OPER>"*"   {if(valid) {i=2; valid=0;}	else ext();}
<OPER>"/"   {if(valid) {i=3; valid=0;}	else ext();}
<OPER>[a-zA-Z0-9]+ {if(!valid) {valid=1; opnd++; a[i]++;}	else ext();}
<OPER>"\n"  {if(valid) return 0;	else ext();}
.\n	    ext();

%%

int ext()	{
	printf("Invalid Expression");	exit(0);
}
int main()	{
	printf("Enter expression");	yylex();
	printf("Valid expression.\n");
	printf("No of operands\identifiers : %d\n", opnd);
	printf("No of +, -, *, / : %d, %d, %d, %d\n", a[0], a[1], a[2], a[3]);
}