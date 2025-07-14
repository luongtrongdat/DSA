#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int front;
    int rear;
    int capacity;
} Queue;

Queue createQueue(int capacity) {
    Queue q;
    q.array = (int *)malloc(capacity * sizeof(int));
    q.front = 0;
    q.rear = -1;
    q.capacity = capacity;
    return q;
}

int main() {
    int size = 5;
    Queue myQueue = createQueue(size);
    printf("Front: %d\n", myQueue.front);
    printf("Rear: %d\n", myQueue.rear);
    printf("Max Size: %d\n", myQueue.capacity);
    free(myQueue.array);
    return 0;
}