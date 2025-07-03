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
Node* delete(Node* head,int num) {
    if (head == NULL) {
        return NULL;
    }
    while (head!=NULL &&head->data == num) {
        Node* temp = head;
        head=temp->next;
        free(temp);
    }
    Node* current = head;
    while (current->next != NULL) {
        if (current->next->data==num) {
            Node* temp = current->next;
            current->next=current->next->next;
            free(temp);
        }else {
            current = current->next;
        }
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
    printf("Nhap gia tri can xoa: ");
    int num;
    scanf("%d",&num);
    head=delete(head,num);
    printf("Sau khi xoa\n");
    printList(head);
    return 0;
}