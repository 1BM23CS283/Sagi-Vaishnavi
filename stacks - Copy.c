

#include<stdio.h>
#include<stdlib.h>
#define max 5
int stack[max];
int top=-1;
void push(int);
int pop();
void display();
void main()
{

    int option,num;
    do{
        printf("1.push\n2.pop\n3.display\n4.exit\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("enter the number:\n");
            scanf("%d",&num);
            push(num);
            break;
        case 2:
            int a=pop();
            printf("element popped:%d",a);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("enter valid number\n");

        }
    }while(option!=4);
}
void push(int num)
{
    if(top==max-1)
    {
        printf("stack overflow\n");



    }
    else{
        top++;
        stack[top]=num;
    }
    printf("element pushed\n");

}
int pop()
{

    if(top==-1)
    {

        printf("stack underflow\n");
        return -1;
    }
    else{
        int n=stack[top];
        top--;
        return n;
    }

}

void display()
{

    if(top==-1)
    {

        printf("stack is empty\n");
    }
    else{
        for(int i=top;i>=0;i--)
        {
            printf("%d\t",stack[i]);
        }
        printf("\n");
    }
}

