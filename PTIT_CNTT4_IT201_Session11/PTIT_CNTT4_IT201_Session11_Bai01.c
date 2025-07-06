#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
Node* insertNode(Node* head, int value) {
    if (head == NULL) {
        return createNode(value);
    }
    Node* newNode = createNode(value);
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}
void printList(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main() {
    Node* head = NULL;
    head=insertNode(head, 1);
    head=insertNode(head, 2);
    head=insertNode(head, 3);
    head=insertNode(head, 4);
    head=insertNode(head, 5);
    printList(head);
    return 0;
}