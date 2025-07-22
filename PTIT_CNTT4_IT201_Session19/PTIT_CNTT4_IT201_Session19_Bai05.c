#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool dfs(Node* root, int value) {
    if (root == NULL) return false;
    if (root->data == value) return true;
    return dfs(root->left, value) || dfs(root->right, value);
}

int main(void) {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int n;
    printf("Nhap gia tri can tim kiem: ");
    scanf("%d", &n);

    if (dfs(root, n)) printf("True\n");
    else printf("False\n");

    return 0;
}