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

int findMax(Node* root) {
    if (root == NULL) return -999999;

    int maxLeft = findMax(root->left);
    int maxRight = findMax(root->right);

    int maxSub = (maxLeft > maxRight) ? maxLeft : maxRight;
    return (root->data > maxSub) ? root->data : maxSub;
}

int main(void) {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printf("Max Value: %d\n", findMax(root));
    return 0;
}
