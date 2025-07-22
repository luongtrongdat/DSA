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

// -------------------- Hàng đợi dùng mảng --------------------
#define MAX_QUEUE 100

typedef struct {
    Node* data[MAX_QUEUE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    return q;
}

bool isEmpty(Queue* q) {
    return q->front > q->rear;
}

void enqueue(Queue* q, Node* node) {
    if (q->rear < MAX_QUEUE - 1) {
        q->data[++q->rear] = node;
    }
}

Node* dequeue(Queue* q) {
    if (!isEmpty(q)) {
        return q->data[q->front++];
    }
    return NULL;
}

void freeQueue(Queue* q) {
    free(q); // chỉ cần giải phóng bộ nhớ của queue
}

// -------------------- Thêm phần tử không theo thứ tự --------------------
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
        } else {
            enqueue(q, current->left);
        }

        if (current->right == NULL) {
            current->right = createNode(value);
            freeQueue(q);
            return;
        } else {
            enqueue(q, current->right);
        }
    }

    freeQueue(q);
}

// -------------------- Duyệt theo tầng (BFS) --------------------
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
    printf("\nNhap so muon them: ");
    scanf("%d", &n);

    addValue(root, n);

    printf("\nAfter:\n");
    printLevelOrder(root);

    return 0;
}