#include <stdio.h>

void addEdge(int n, int arr[n][n], int startNode, int endNode) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == startNode && j == endNode) {
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
    int arr[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    addEdge(3, arr, 1, 2);
    printLink(3, arr);
    return 0;
}