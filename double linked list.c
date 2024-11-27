#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertLeft(struct Node** head, struct Node* node, int value) {
    if (node == NULL) {
        printf("The node is NULL. Insertion failed.\n");
        return;
    }

    struct Node* newNode = createNode(value);

    newNode->next = node;
    newNode->prev = node->prev;

    if (node->prev != NULL) {
        node->prev->next = newNode;
    } else {
        *head = newNode;
    }

    node->prev = newNode;
}


void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head;

    if (temp == NULL) {
        printf("The list is empty. Deletion failed.\n");
        return;
    }

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    if (*head == temp) {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp); 
}


void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    head = createNode(10);
    head->next = createNode(20);
    head->next->prev = head;
    head->next->next = createNode(30);
    head->next->next->prev = head->next;

   
    printf("Original list: ");
    displayList(head);

    printf("\nInserting 15 to the left of node 20...\n");
    insertLeft(&head, head->next, 15);

    
    printf("List after insertion: ");
    displayList(head);

   
    printf("\nDeleting node with value 20...\n");
    deleteNode(&head, 20);

    printf("List after deletion: ");
    displayList(head);

    return 0;
}
