#include <stdio.h>
#include <string.h>
int k = 0, z = 0, i = 0, j = 0, c = 0;
char a[16] = {'i', 'd', '+', 'i', 'd', '*', 'i', 'd'}, ac[20], stk[15], act[10];
void check();
void main()
{
    printf("Grammar is E->E+T|T \n T->T*F|F \n F->(E) \n F->id");
    printf("Enter the input string");
    scanf("%s",a);
    c = strlen(a);      //  c = Length of Input String
    strcpy(act, "SHIFT->");     
    puts("Stack \t Input \t Action");
    for (k = 0, i = 0; j < c; k++, i++, j++)
    {
        if (a[j] == 'i' && a[j + 1] == 'd')
        {
            stk[i] = a[j];
            stk[i + 1] = a[j + 1];
            stk[i + 2] = '\0';
            a[j] = ' ';
            a[j + 1] = ' ';
            printf("\n$%s\t%s$\t%sid", stk, a, act);
            check();
        }
        else
        {
            stk[i] = a[j];
            stk[i + 1] = '\0';
            a[j] = ' ';
            printf("\n$%s\t%s$\t%ssymbol", stk, a, act);
            check();
        }
    }
}
void check()
{
    strcpy(ac, "REDUCE F->id");
    for (z = 0; z < c; z++)
        if (stk[z] == 'i' && stk[z + 1] == 'd')
        {
            stk[z] = 'F';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            j++;
        }
    strcpy(ac, "REDUCE T->T*F");
    for (z = 0; z < c; z++)
        if (stk[z] == 'T' && stk[z + 1] == '*' && stk[z + 2] == 'F')
        {
            stk[z] = 'T';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            i = i - 2;
        }
    strcpy(ac, "REDUCE T->F");
    for (z = 0; z < c; z++)
        if (stk[z] == 'F')
        {
            stk[z] = 'T';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
        }
    strcpy(ac, "REDUCE E->E+T");
    for (z = 0; z < c; z++)
    {
        if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'T' && stk[z + 3] != '*' && a[j + 1] != '*')
        {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            stk[z + 3] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            i = i - 2;
        }
        else if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'T' && j == c)
        {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            i = i - 2;
        }
        else
            break;
    }
    strcpy(ac, "REDUCE E->T");
    for (z = 0; z < c; z++)
        if (stk[z] == 'T')
        {
            if (a[j + 1] == '+' || a[j + 1] == '\0')
            {
                stk[z] = 'E';
                stk[z + 1] = '\0';
                printf("\n$%s\t%s$\t%s", stk, a, ac);
            }
            else
                break;
        }
    strcpy(ac, "REDUCE F->(E)");
    for (z = 0; z < c; z++)
        if (stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')')
        {
            stk[z] = 'F';
            stk[z + 1] = '\0';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            i = i - 2;
        }
}
