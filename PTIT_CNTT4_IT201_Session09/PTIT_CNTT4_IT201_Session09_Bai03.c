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
int findNum(Node* head,int num) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == num) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}
int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    int num;
    printf("Nhap vao so can kiem tra: ");
    scanf("%d", &num);
    if (findNum(head,num)) {
        printf("True");
    }else {
        printf("False");
    }
    return 0;
}