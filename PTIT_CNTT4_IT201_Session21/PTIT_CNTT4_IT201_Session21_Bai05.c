#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void addEdge(int n, Node *arr[n], int firstNode, int seccontNode) {
    for (int i = 0; i < n; i++) {
        if (i == firstNode) {
            Node *newNode = createNode(seccontNode);
            newNode->next = arr[i];
            arr[i] = newNode;
            return;
        }
    }
}

void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL");
}

void printLink(int n, Node *arr[n]) {
    for (int i = 0; i < n; i++) {
        printList(arr[i]);
        printf("\n");
    }
}

void noVecter(int n, Node *arr[n], int firstNode, int secconNode) {
    addEdge(n, arr, firstNode, secconNode);
    addEdge(n, arr, secconNode, firstNode);
}

int main() {
    Node *arr[3] = {NULL,NULL,NULL};
    noVecter(3, arr, 1, 2);
    noVecter(3, arr, 0, 1);
    printLink(3, arr);
    return 0;
}