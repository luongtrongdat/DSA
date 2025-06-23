//
// Created by Windows on 23/06/2025.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int m;
    do {
        printf("Nhap so luong phan tu: ");
        scanf("%d", &n);
    } while (n < 0 || n >= 1000);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Loi!!");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    do {
        printf("Nhap so phan tu muon them: ");
        scanf("%d", &m);
    } while (m < 0 || m >= 1000);
    arr = (int *)realloc(arr, (n +m) * sizeof(int));
    if (arr == NULL) {
        printf("Loi!!");
        return 1;
    }
    for (int i = n; i < (n + m); i++) {
        printf("Nhap phan tu: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Mang sau khi them: ");
    for (int i = 0; i < (n + m); i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}