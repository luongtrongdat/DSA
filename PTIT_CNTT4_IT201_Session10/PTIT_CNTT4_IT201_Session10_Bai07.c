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
void sort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    Node* current = head;
    for (int i = 0; i < length(head); i++) {
        current=head;
        for (int j = 0; j < length(head)-i-1; j++) {
            if (current->data > current->next->data) {
                int temp=current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
            current = current->next;
        }

    }
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
    printf("Sort\n");
    sort(head);
    printList(head);
    return 0;
}