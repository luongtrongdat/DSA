#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep trong\n");
        return -1;
    }
    return stack->top->data;
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
    Stack* s = createStack();
    push(s, 5);
    push(s, 4);
    push(s, 3);
    push(s, 2);
    push(s, 1);
    printStack(s);
    int topValue = peek(s);
    if (topValue != -1) {
        printf("%d\n", topValue);
    }
    Stack* empty = createStack();
    peek(empty);
    return 0;
}