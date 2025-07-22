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

// -------------------- Thêm phần tử không tứ tự --------------------
void addValue(Node* root, int value) {
    if (root == NULL) return;

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        Node* current = dequeue(q);

        if (current->left == NULL) {
            current->left = createNode(value);
            freeQueue(q);
            return;
        }else {
            enqueue(q, current -> left);
        }

        if (current->right == NULL) {
            current->right = createNode(value);
            freeQueue(q);
            return;
        }else {
            enqueue(q, current->right);
        }
    }
}

void printLevelOrder(Node* root) {
    if (root == NULL) return;

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        printf("%d ", current->data);
        if (current->left) enqueue(q, current->left);
        if (current->right) enqueue(q, current->right);
    }

    freeQueue(q);
}

// -------------------- Main --------------------
int main(void) {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printf("Before:\n");
    printLevelOrder(root);

    int n;
    printf("\n Nhap so muon them: ");
    scanf("%d", &n);

    addValue(root, n);

    printf("\nAfter:\n");
    printLevelOrder(root);


    return 0;
}