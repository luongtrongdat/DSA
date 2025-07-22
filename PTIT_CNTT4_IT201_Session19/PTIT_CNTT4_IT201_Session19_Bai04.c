#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* inorder(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
    return root;
}

int main(void) {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    printf("Preorder Traversal:\n");
    inorder(root);
    return 0;
}