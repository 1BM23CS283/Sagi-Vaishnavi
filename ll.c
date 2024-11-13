#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertAtFirst(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}


void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    struct Node* newNode = createNode(data);
    if (position == 1) {
        insertAtFirst(head, data);
        return;
    }
    struct Node* current = *head;
    int count = 1;
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteAtFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtPosition(struct Node** head, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 1) {
        deleteAtFirst(head);
        return;
    }
    struct Node* current = *head;
    int count = 1;
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }
    if (current == NULL || current->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printf("List after inserting 10, 20, 30 at the end:\n");
    display(head);

    insertAtFirst(&head, 5);
    printf("List after inserting 5 at the beginning:\n");
    display(head);

    insertAtPosition(&head, 15, 3);
    printf("List after inserting 15 at position 3:\n");
    display(head);

    deleteAtFirst(&head);
    printf("List after deleting the first node:\n");
    display(head);

    deleteAtPosition(&head, 2);
    printf("List after deleting node at position 2:\n");
    display(head);

    deleteAtEnd(&head);
    printf("List after deleting the last node:\n");
    display(head);

    return 0;
}
