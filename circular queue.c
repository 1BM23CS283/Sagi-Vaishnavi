#include <stdio.h>
#include <stdlib.h>

#define max 5

int q[max];
int rear = -1;
int front = -1;

void enqueue(int);
int dequeue();
void display();

int main() {
    int option;
    do {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your option:\n");
        scanf("%d", &option);
        switch (option) {
            case 1: {
                int num;
                printf("Enter the number:\n");
                scanf("%d", &num);
                enqueue(num);
                break;
            }
            case 2: {
                int a = dequeue();
                if (a != -1) {
                    printf("Deleted element is %d\n", a);
                }
                break;
            }
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Incorrect option\n");
        }
    } while (option != 4);

    return 0;
}

void enqueue(int num) {
    if ((front == 0 && rear == max - 1) || (front == rear + 1)) {
        printf("Queue is full\n");
    } else {
        if (front == -1 && rear == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % max;
        }
        q[rear] = num;
    }
}

int dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int a = q[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % max;
        }
        return a;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d\t", q[i]);
        if (i == rear) break;
        i = (i + 1) % max;
    }
    printf("\n");
}


