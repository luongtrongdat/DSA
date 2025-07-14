#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) exit(1);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

typedef struct Stack {
    Node* top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) exit(1);
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
}

void printStack(Stack* stack) {
    Node* current = stack->top;
    printf("stack = {\n  ");
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n}\n");
}

int main() {
    Stack* myStack = createStack();
    push(myStack, 5);
    push(myStack, 4);
    push(myStack, 3);
    push(myStack, 2);
    push(myStack, 1);
    printStack(myStack);
    int n;
    printf("Nhap so nguyen duong can them vao stack: ");
    scanf("%d", &n);
    if (n > 0) {
        push(myStack, n);
        printStack(myStack);
    } else {
        printf("Chi nhap so nguyen duong.\n");
    }
    return 0;
}