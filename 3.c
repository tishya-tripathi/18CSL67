#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char prod[3][10] = {"A->aBa", "B->bB", "B->@"}, input[10], stack[25];
int top = -1;
int j = 0, k, l;
void push(char item)
{
    stack[++top] = item;
}
void pop()
{
    top--;
}
void display()
{
    for (int j = top; j >= 0; j--)
        printf("%c", stack[j]);
}
void stackpush(char p)
{
    pop();
    if (p == 'A')
        for (j = strlen(prod[0]) - 1; j >= 3; j--)
            push(prod[0][j]);
    else
        for (j = strlen(prod[1]) - 1; j >= 3; j--)
            push(prod[1][j]);
}
void main()
{
    char c;
    int i;
    printf("first(A)={a}\tfollow(A)={$}\nfirst(B)={b,@}\tfollow(B)={a}\n\n\t a \t b \t $ \n");
    printf("A\t%s\nB\t%s\t%s\n", prod[0], prod[2], prod[1]);
    printf("enter the input string terminated with $ to parse:-");
    scanf("%s", input);
    for (i = 0; input[i] != '\0'; i++)
        if (input[i] != 'a' && input[i] != 'b' && input[i] != '$')
        {
            printf("invalid string");
            exit(0);
        }
    push('$');
    push('A');
    i = 0;
    printf("\n\nstack\tInput\taction\n---------\n");
    while (i != strlen(input) && stack[top] != '$')
    {
        //  Print the contents of STACK(for: top -> 0) and INPUT(for:  i -> strlen(input)) 
        printf("\n");
        for (l = top; l >= 0; l--)
            printf("%c", stack[l]);
        printf("\t");
        for (l = i; l < strlen(input); l++)
            printf("%c", input[l]);
        printf("\t");
        // --------------------------------------------------------

        if (stack[top] == 'A')
        {
            printf("A->aBa");
            stackpush('A');
        }
        else if (stack[top] == 'B')
            if (input[i] != 'b')
            {
                printf("B->@\t matched @");
                pop();
            }
            else
            {
                printf("B->bB");
                stackpush('B');
            }
        else if (stack[top] == input[i])
        {
            printf("pop%c\tmatched %c", input[i], input[i]);
            pop();
            i++;
        }
        else
            break;
    }
    if (stack[top] == '$' && input[i] == '$')
        printf("\n$\t$\nValid string Accepted\n");
    else
        printf("\nInvalid string rejected\n");
}