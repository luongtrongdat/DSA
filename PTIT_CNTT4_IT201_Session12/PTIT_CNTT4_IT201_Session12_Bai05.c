#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
Node* insertNode(Node* head, int data) {
    if (head == NULL) {
        return createNode(data);
    }
    Node* newNode = createNode(data);
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}
Node* deleteNode(Node* head,int value) {
    if (head == NULL) {
        return NULL;
    }
    while (head->data == value) {
        if (head->next != NULL) {
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            free(temp);
        }else {
            free(head);
            return NULL;
        }
    }
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            Node* temp = current;
            if (current->next != NULL) {
                current->prev->next = current->next;
                current->next->prev = current->prev;

            }else {
                current->prev->next = NULL;
            }
            current = current->next;
            free(temp);
        }else {
            current = current->next;
        }
    }
    return head;
}
void printNode(Node* head) {
    if (head == NULL) {
        printf("Danh sach trong");
        return;
    }
    Node* current=head;
    while (current != NULL) {
        printf("data: %d\n",current->data);
        current=current->next;
    }
}
int main() {
    Node* head = NULL;
    int n,value;
    printf("Nhap vao so luong pha tu: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        printf("Nhap vao gia tri index %d: ",i);
        scanf("%d",&value);
        head = insertNode(head,value);
    }
    printNode(head);
    printf("Nhap vao gia tri can xoa: ");
    scanf("%d",&value);
    head=deleteNode(head,value);
    printNode(head);
    return 0;
}