#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Stack {
    Node* top;
} Stack;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

void push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int main() {
    Stack* s1 = createStack();
    push(s1, 5);
    push(s1, 4);
    push(s1, 3);
    push(s1, 2);
    push(s1, 1);
    if (isEmpty(s1)) {
        printf("Ngăn xếp trống\n");
    } else {
        Node* current = s1->top;
        while (current != NULL) {
            printf("%d\n", current->data);
            current = current->next;
        }
    }
    return 0;
}