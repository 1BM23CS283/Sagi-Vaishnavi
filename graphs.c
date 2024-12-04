#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}
void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
void display(struct Node* root) {
    printf("In-order traversal: ");
    inorder(root);
    printf("\n");
   
    printf("Pre-order traversal: ");
    preorder(root);
    printf("\n");
   
    printf("Post-order traversal: ");
    postorder(root);
    printf("\n");
}
int main() {
    struct Node* root = NULL;
    int data;
    int choice;
    while (1) {
        printf("Enter a number to insert into the BST (0 to stop): ");
        scanf("%d", &data);
        if (data == 0) {
            break;
        }
        root = insert(root, data);
    }
    display(root);
    return 0;
}
