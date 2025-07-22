#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Cau truc cay nhi phan
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//DFS
Node* preorder(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
    return root;
}

Node* inorder(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
    return root;
}

Node* postorder(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
    return root;
}


// Cau truc Queue
typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
}QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
}Queue;

Queue* createQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

bool isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, Node* treeNode) {
    QueueNode* newQueueNode =(QueueNode*)malloc(sizeof(QueueNode));
    newQueueNode->treeNode = treeNode;
    newQueueNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newQueueNode;
        return;
    }
    queue->rear->next = newQueueNode;
    queue->rear = newQueueNode;
}

Node* dequeue(Queue* queue) {
    if (isEmpty(queue)) return NULL;
    QueueNode* temp = queue->front;
    Node* treeNode = temp->treeNode;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return treeNode;
}

//BFS
void BFS(Node* root) {
    if (root == NULL) return;
    Queue* queue = createQueue();
    enqueue(queue, root);
    while (!isEmpty(queue)) {
        Node* current = dequeue(queue);
        printf("%d ", current->data);
        if (current->left != NULL) {
            enqueue(queue, current->left);
        }
        if (current->right != NULL) {
            enqueue(queue, current->right);
        }
    }
}

int main(void) {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n");
    printf("BFS: ");
    BFS(root);
    printf("\n");
    return 0;
}