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
    } while (rows <= 0 || cols <= 0);
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    if (rows != cols) {
        printf("Loi!!\n");
        return 0;
    }
    int duongCheoChinh = 0;
    int duongCheoPhu = 0;
    for (int i = 0; i < rows; i++) {
        duongCheoChinh += arr[i][i];
        duongCheoPhu += arr[i][cols - 1 - i];
    }
    printf("duongCheoChinh: %d\n", duongCheoChinh);
    printf("duongCheoPhu: %d\n", duongCheoPhu);
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}