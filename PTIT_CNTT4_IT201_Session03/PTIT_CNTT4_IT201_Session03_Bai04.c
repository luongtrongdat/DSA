// 2 chieu: (kieu du lieu) ** (ten bien) = (kieu du lieu **)malloc (so luong phan tu) du lieu * sizeof (kieu du lieu *))


#include <stdio.h>
#include <stdlib.h>

int findMax(int **arr, int rows, int cols) {
    int max = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}

int findMin(int **arr, int rows, int cols) {
    int min = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    return min;
}

int main() {
    int rows, cols;
    do {
        printf("Nhap so hang (0 < rows < 1000): ");
        scanf("%d", &rows);
    } while (rows <= 0 || rows >= 1000);
    do {
        printf("Nhap so cot: ");
        scanf("%d", &cols);
    } while (cols <= 0 || cols >= 1000);
    int **arr = (int **)malloc(rows * sizeof (int *));
    if (arr == NULL) {
        printf("Loi!!\n");
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof (int));
        if (arr[i] == NULL) {
            printf("Loi!!\n", i);
            for (int j = 0; j < i; j++) {
                free(arr[j]);
            }
            free(arr);
            return 1;
        }
    }
    printf("Nhap cac phan tu cho mang: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("So lon nhat trong mang la: %d \n", findMax(arr, rows, cols));
    printf("So nho nhat trong mang la: %d \n", findMin(arr, rows, cols));
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}