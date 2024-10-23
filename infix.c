
#include<stdio.h>
#include<string.h>
int top=-1,pos=0,length,index1=0;
char symbol,temp,infix[50],postfix[50],stack[50];
void push(char);
char pop();
void infixtopostfix();
int pref(char);
void main()
{
    printf("enter the infix expression:\n");
    scanf("%s",infix);
    infixtopostfix();
    printf("infix expression:%s",infix);
    printf("postfix expression:%s",postfix);
}
void infixtopostfix()
{
    length=strlen(infix);
    push('#');
    while(index1<length)
    {
        symbol=infix[index1];
        switch(symbol)
        {
            case'(':
                push(symbol);
                break;
            case ')':
                temp=pop();
                while(temp!='(')
                {
                    postfix[pos++]=temp;

                    temp=pop();
                }

                break;
            case '*':
            case '/':
            case'^':
            case '+':
            case '-':
                while(pref(stack[top])>=pref(symbol))
                {
                    temp=pop();
                    postfix[pos++]=temp;
                }
                push(symbol);
                break;
            default:
                postfix[pos++]=symbol;
            }
            index1++;

    }
     while(top>0)
        {
            temp=pop();
            postfix[pos++]=temp;
        }
}
void push(char symbol)
{
    top++;
    stack[top]=symbol;
}
char pop()
{
    char symb;
    symb=stack[top];
    top--;
    return symb;
}
int pref(char symbol)
{
    int num;
    switch(symbol)
    {
        case '^':
            num=3;
            break;
        case '*':
        case '/':
            num=2;
            break;
        case '+':
        case '-':
            num=1;
            break;
        case '(':
            num=0;
            break;
        case '#':
            num=-1;
            break;

    }
    return num;
}

