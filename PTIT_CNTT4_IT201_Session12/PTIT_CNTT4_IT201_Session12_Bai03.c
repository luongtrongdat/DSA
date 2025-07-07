#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
Node* insertNode(Node* head, int data) {
    if (head == NULL) {
        return createNode(data);
    }
    Node* newNode = createNode(data);
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}
Node* insertNodeAtLast(Node* head, int data) {
    if (head == NULL) {
        return createNode(data);
    }
    Node* newNode = createNode(data);
    Node* current=head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}
void printNode(Node* head) {
    if (head == NULL) {
        printf("Danh sach trong");
        return;
    }
    Node* current=head;
    while (current != NULL) {
        printf("data: %d\n",current->data);
        current=current->next;
    }
}
int main() {
    Node* head = NULL;
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);
    head = insertNode(head, 4);
    head = insertNode(head, 5);
    printNode(head);
    head = insertNodeAtLast(head, 0);
    printNode(head);
    return 0;
}