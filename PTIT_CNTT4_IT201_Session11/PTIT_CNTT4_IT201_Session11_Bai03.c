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
    int i=1;
    while (temp != NULL) {
        printf("Node %d: %d\n",i, temp->data);
        temp = temp->next;
        i++;
    }
}
int find(Node* head,int value) {
    if (head == NULL) {
        return 0;
    }
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
int main() {
    Node* head = NULL;
    head=insertNode(head, 1);
    head=insertNode(head, 2);
    head=insertNode(head, 3);
    head=insertNode(head, 4);
    head=insertNode(head, 5);
    printList(head);
    int findNum;
    printf("Nhap vao gia tri can tim: ");
    scanf("%d",&findNum);
    if (find(head,findNum)) {
        printf("Tim thay gia tri");
    }else {
        printf("Khong tim thay gia tri");
    }
    return 0;
}