//
// Created by Windows on 23/06/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows;
    int cols;
    do {
        printf("Nhap so hang trong mang: ");
        scanf("%d", &rows);
        printf("Nhap so cot trong mang: ");
        scanf("%d", &cols);
    } while (rows <= 0 || rows >= 1000 || cols <= 0);
    int **arr = (int **)malloc(rows * sizeof(int *));
    if (arr == NULL) {
        printf("Loi!!\n");
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
        if (arr[i] == NULL) {
            printf("Loi!!\n");
            return 1;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    int pos;
    do {
        printf("Nhap so hang de tinh tong: ", rows);
        scanf("%d", &pos);
    } while (pos < 1 || pos > rows);
    int sum = 0;
    for (int j = 0; j < cols; j++) {
        sum += arr[pos - 1][j];
    }
    printf("Mang cua ban: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
    }
    printf("Tong cac phan tu cua hang %d la: %d\n", pos, sum);
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}