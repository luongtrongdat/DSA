#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// -------------------- Cấu trúc cây nhị phân --------------------
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// -------------------- Cấu trúc Queue --------------------
typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, Node* treeNode) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

Node* dequeue(Queue* q) {
    if (isEmpty(q)) return NULL;

    QueueNode* temp = q->front;
    Node* treeNode = temp->treeNode;

    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return treeNode;
}

void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

// -------------------- Tìm kiếm BFS --------------------
bool bfs(Node* root, int value) {
    if (root == NULL) return false;

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        Node* current = dequeue(q);

        if (current->data == value) {
            freeQueue(q);
            return true;
        }

        if (current->left != NULL)
            enqueue(q, current->left);
        if (current->right != NULL)
            enqueue(q, current->right);
    }

    freeQueue(q);
    return false;
}

// -------------------- Main --------------------
int main(void) {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int n;
    printf("Nhap so can tim: ");
    scanf("%d", &n);

    if (bfs(root, n)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}