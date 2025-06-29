#include <stdio.h>

void maxAndMin(int arr[], int maxMin[], int i, int n) {
    if (i == n) {
        return;
    }
    if (arr[i] > maxMin[0]) {
        maxMin[0] = arr[i];
    }
    if (arr[i] < maxMin[1]) {
        maxMin[1] = arr[i];
    }
    maxAndMin(arr, maxMin, i + 1, n);
}
int main() {
    int n;
    printf("Nhap do dai mang");
    scanf("%d", &n);
    if (n < 0) {
        printf("Gia tri khong hop le");
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu co chi so la [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int maxMin[2];
    maxMin[0] = arr[0];
    maxMin[1] = arr[0];
    maxAndMin(arr, maxMin, 0, n);
    printf("Max min = %d, Min = %d\n", maxMin[0], maxMin[1]);
    return 0;
}