#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;
Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void printList(Node* head) {
    Node* current = head;
    int i=1;
    while (current != NULL) {
        printf("Node %d: %d\n",i, current->data);
        current = current->next;
        i++;
    }
}
int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    printList(head);
    return 0;
}