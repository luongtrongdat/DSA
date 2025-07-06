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
Node* deleteNode(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* temp=head->next;
    if (temp!=NULL) {
        temp->prev = NULL;
    }
    free(head);
    return temp;
}
Node* deleteNodeAtIndex(Node* head, int index) {
    if (head == NULL) {
        printf("Danh sach trong");
        return NULL;
    }
    if (index == 0) {
        return deleteNode(head);
    }
    Node* current = head;
    int i=0;
    while (current != NULL&&i<index) {
        current=current->next;
        i++;
    }
    if (current == NULL) {
        printf("index khong ton tai");
        return head;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    current->prev->next=current->next;
    free(current);
    return head;
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
int main() {
    Node* head = NULL;
    head=insertNode(head, 1);
    head=insertNode(head, 2);
    head=insertNode(head, 3);
    head=insertNode(head, 4);
    head=insertNode(head, 5);
    printList(head);
    int index;
    printf("Moi nhap index can xoa: ");
    scanf("%d",&index);
    if (index<0) {
        printf("Gia tri khong hop le");
        return 0;
    }
    head=deleteNodeAtIndex(head, index);
    printList(head);
    return 0;
}