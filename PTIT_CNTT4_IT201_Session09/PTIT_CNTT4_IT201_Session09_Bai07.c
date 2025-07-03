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
Node* insertNode(Node* head,int index,int num) {
    Node* newNode = createNode(num);
    if (index == 1) {
        newNode->next = head;
        return newNode;
    }
    Node* curren=head;
    for (int i=1;curren!=NULL&&i<index-1;i++) {

        curren=curren->next;
    }
    if (curren==NULL) {
        printf("Vi tri khong ton tai");
        free(newNode);
        return head;
    }
    newNode->next=curren->next;
    curren->next=newNode;
    return head;
}
int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    int index,num;
    printf("Nhap vao index muon them: ");
    scanf("%d", &index);
    if (index<=0) {
        printf("Gia tri khong hop le");
        return 0;
    }
    printf("Nhap vao so muon them: ");
    scanf("%d", &num);
    head=insertNode(head,index,num);
    printList(head);
    return 0;
}