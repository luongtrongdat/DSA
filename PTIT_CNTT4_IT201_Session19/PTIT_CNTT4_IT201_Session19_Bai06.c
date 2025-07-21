#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *creatNode(int data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

void inOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int checkNum(Node *root, int num) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == num) {
        return 1;
    }
    return checkNum(root->left, num) + checkNum(root->right, num);
}

//BFS
typedef struct NodeBFS {
    Node *current;
    struct NodeBFS *next;
} NodeBFS;

NodeBFS *creatNodeBFS(Node *node) {
    NodeBFS *nodeBFS = (NodeBFS *) malloc(sizeof(NodeBFS));
    nodeBFS->current = node;
    nodeBFS->next = NULL;
    return nodeBFS;
}

typedef struct {
    NodeBFS *front;
    NodeBFS *rear;
} Queue;

void enQueue(Queue *q, Node *node) {
    NodeBFS *newNodeBFS = creatNodeBFS(node);
    if (q->front == NULL) {
        q->front = newNodeBFS;
        q->rear = newNodeBFS;
        return;
    }
    q->rear->next = newNodeBFS;
    q->rear = newNodeBFS;
}

Node *deQueue(Queue *q) {
    if (q->rear == NULL) {
        return NULL;
    }
    NodeBFS *current = q->front;
    Node *tempCurrent = current->current;
    q->front = current->next;
    free(current);
    return tempCurrent;
}

void freeQueue(Queue *q) {
    NodeBFS *temp = NULL;
    NodeBFS *current = q->front;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(q);
}

void levelOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->rear = NULL;
    q->front = NULL;
    enQueue(q, root);
    while (q->front != NULL) {
        Node *current = deQueue(q);
        printf("%d ", current->data);
        if (current->left != NULL) {
            enQueue(q, current->left);
        }
        if (current->right != NULL) {
            enQueue(q, current->right);
        }
    };
    freeQueue(q);
}

int checkBFS(Node *root, int num) {
    if (root == NULL) {
        return 0;
    }
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->rear = NULL;
    q->front = NULL;
    enQueue(q, root);
    while (q->front != NULL) {
        Node *current = deQueue(q);
        if (current->data == num) {
            freeQueue(q);
            return 1;
        }
        if (current->left != NULL) {
            enQueue(q, current->left);
        }
        if (current->right != NULL) {
            enQueue(q, current->right);
        }
    };
    freeQueue(q);
    return 0;
}

void addToTree(Node *root, int num) {
    if (root == NULL) {
        return;
    }
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->rear = NULL;
    q->front = NULL;
    enQueue(q, root);
    while (q->front != NULL) {
        Node *current = deQueue(q);
        if (current->left != NULL) {
            enQueue(q, current->left);
        } else {
            current->left = creatNode(num);
            break;
        }
        if (current->right != NULL) {
            enQueue(q, current->right);
        } else {
            current->right = creatNode(num);
            break;
        }
    };
    freeQueue(q);
}

int height(Node *root) {
    if (root == NULL) {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return left > right ? left + 1 : right + 1;
}

void freeAll(Node *root) {
    if (root == NULL) {
        return;
    }
    freeAll(root->left);
    freeAll(root->right);
    free(root);
}

int main() {
    Node *root = creatNode(2);
    root->left = creatNode(3);
    root->right = creatNode(4);
    root->left->left = creatNode(5);
    printf("\nPreOrder\n");
    preOrder(root);
    printf("\nPostOrder\n");
    postOrder(root);
    printf("\nInOrder\n");
    inOrder(root);
    int num;
    printf("\nVui long nhap so ca kiem tra: ");
    scanf("%d", &num);
    if (checkNum(root, num)) {
        printf("True");
    } else {
        printf("False");
    }
    printf("\nVui long nhap so ca kiem tra: ");
    scanf("%d", &num);
    if (checkBFS(root, num)) {
        printf("True");
    } else {
        printf("False");
    }
    printf("\nVui long nhap so ca them: ");
    scanf("%d", &num);
    addToTree(root, num);
    printf("\nPreOrder\n");
    preOrder(root);
    printf("\nChieu cao cua cay la %d", height(root));
    freeAll(root);
    return 0;
}