#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;
Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}
Node* insert(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("data: %d\n",current->data);
        current = current->next;
    }
}
int main() {
    Node* head = NULL;
    for (int  i=0;i<5;i++) {
        int num;
        printf("Nhap vao gia tri can them: ");
        scanf("%d",&num);
        head=insert(head,num);
    }
    printList(head);
    return 0;
}