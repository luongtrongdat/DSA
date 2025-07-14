#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

typedef struct Stack {
    Node* top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

int main() {
    Stack* myStack = createStack();
    return 0;
}