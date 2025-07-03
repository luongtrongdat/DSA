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
Node* deleteNode(Node* head,int index) {
    if (index == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* curren=head;
    for (int i = 1; i < index; i++) {
        if (curren->next == NULL) {
            printf("Index khong ton tai");
            return head;
        }
        curren=curren->next;
    }
    Node* temp = curren->next;
    if (temp==NULL) {
        printf("Index khong ton tai");
        return head;
    }
    curren->next=temp->next;
    free(temp);
    return head;
}
int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    int index;
    printf("Nhap vao index muon xoa");
    scanf("%d", &index);
    if (index<=0) {
        printf("Gia tri khong hop le");
        return 0;
    }
    head=deleteNode(head,index);
    printList(head);
    return 0;
}
