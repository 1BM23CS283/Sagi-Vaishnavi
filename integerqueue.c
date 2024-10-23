#include<stdio.h>
#include<stdlib.h>
#define max 5
int q[max];
void enqueue(int);
int dequeue();
void display();
int front=-1,rear=-1;
void main()
{
    int option;
    do
    {
        printf("1.enqueue\n 2.dequeue\n 3.display\n");
        printf("enter the option:\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                int num;
                printf("enter the number to insert:\n");
                scanf("%d",&num);
                enqueue(num);
                break;
            case 2:
                int a=dequeue();
                if(a!=-1)
                {
                    printf("popped element is %d\n",a);
                }
                break;
            case 3:
                display();
            default:
                printf("incorrect number\n");
        }
    }while(option!=4);
}
void enqueue(int num)
{
    if(rear==max-1)
    {
        printf("overflow\n");
    }
    else
    {
        if(front==-1&&rear==-1)
        {
            front=0;
            rear=0;
        }
        else
        {
            rear++;
        }
        q[rear]=num;
    }
}
int dequeue()
{
    if(front==-1&&rear==-1)
    {
        printf("empty queue\n");
    }
    else
    {
        int a=q[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front++;
        }
    }
}
void display()
{
    if(front==-1&&rear==-1)
    {
        printf("empty queue\n");
    }
    else
    {
        int i;
        for(i=front;i<=rear;i++);
        {
            printf("%d\t",q[i]);
        }
    }
}
