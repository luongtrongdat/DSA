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
int length(Node* head) {
    Node* current = head;
    int count=0;
    while (current!=NULL) {
        current = current->next;
        count++;
    }
    return count;
}
void midNode(Node* head) {
    int n=length(head);
    if (n<=0) {
        printf("Node trong");
        return;
    }
    Node* current = head;
    for (int i = 0; i < n/2; i++) {
        current = current->next;
    }
    printf("Node %d: %d",n/2+1,current->data);
}
int main() {
    Node* head = NULL;
    for (int  i=0;i<10;i++) {
        int num;
        printf("Nhap vao gia tri can them: ");
        scanf("%d",&num);
        head=insert(head,num);
    }
    printList(head);
    midNode(head);
    return 0;
}