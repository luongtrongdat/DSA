#include <stdio.h>

void addEdge(int n, int arr[n][n], int firstNode, int seccontNode) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == firstNode && j == seccontNode || i == seccontNode && j == firstNode) {
                arr[i][j] = 1;
            }
        }
    }
}

void printLink(int n, int arr[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    addEdge(4, arr, 0, 1);
    addEdge(4, arr, 0, 2);
    addEdge(4, arr, 1, 2);
    addEdge(4, arr, 2, 3);
    printLink(4, arr);
    return 0;
}