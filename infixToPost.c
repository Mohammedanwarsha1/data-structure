#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char A[20],P[20];   //A-to store infix expression   P-to store postfix expression
char S[20];         //stact used for infix to postfix convertion
int top=-1;

int precedence(char c)
{
    switch (c)
    {
    case '+':
    case '-': return 1;

    case '*':
    case '/': return 2;

    case '^': return 3;
    }
}
void infixToPostfix()
{
    int i=0,j=0;
    char x,y;
    while(A[i]!='\0')
    {
        if(isdigit(A[i]))
            P[j++]=A[i];
        else if(A[i]=='(')
            S[++top]=A[i];
        else if(A[i]==')')
        {
            while(S[top]!='(')
                P[j++]=S[top--];
            top--;
        }
        else{
            x=A[i];
            y=S[top];
            if(top==-1 || y=='(' || precedence(y)<precedence(x))
                S[++top]=A[i];
            else{
                while(top!=-1 && y!='(' && precedence(x)<precedence(y))
                {
                    P[j++]=S[top--];
                    y=S[top];
                }
                S[top++]=x;
            
            }
        }
        i++;
    }
    while(top!=-1)
        P[j++]=S[top--];
    P[j]='\0';
    printf("postfix expression is %s",P);
}
void main()
{
    printf("enter the infix expression\n");
    gets(A);
    infixToPostfix();
}