#include <stdio.h>
#include <stdlib.h>
typedef  struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Queue {
    struct Node* front;
    struct Node* rear;
} Queue;
Node* createNode(int data) {
    Node* node=(Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}
Queue* enQueue(Queue* queue, int data) {
    Node* node=createNode(data);
    if(isEmpty(queue)) {
        queue->front = queue->rear = node;
        return queue;
    }
    queue->rear->next=node;
    queue->rear = node;
    return queue;
}
int deQueue(Queue* queue) {
    if(isEmpty(queue)) {
        printf("Queue trong\n");
        return 0;
    }
    Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);
    return data;
}
void firstNode(Queue* queue) {
    if(isEmpty(queue)) {
        printf("Queue trong\n");
        return;
    }
    printf("Gia tri dau queue: %d\n",queue->front->data);
}
void printQueue(Queue* queue) {
    if(isEmpty(queue)) {
        printf("Queue trong\n");
        return;
    }
    Node* temp = queue->front;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void freeQueue(Queue* queue) {
    if(isEmpty(queue)) {
        printf("Queue trong\n");
        return;
    }
    Node* current = queue->front;
    while(current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
}
int main() {
    Queue* queue = createQueue();
    int n,x;
    printf("Moi nhap vao so phan tu: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Nhap vao gia tri: ");
        scanf("%d", &x);
        enQueue(queue, x);
    }
    firstNode(queue);
    printf("Gia tri dau la %d\n",deQueue(queue));
    printQueue(queue);
    freeQueue(queue);
    return 0;
}