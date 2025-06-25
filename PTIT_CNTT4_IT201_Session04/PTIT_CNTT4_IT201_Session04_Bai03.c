#include <stdio.h>

int minFirstNumber(int arr[], int size) {
    if (size <= 0) {
        return -1;
    }
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[min]) {
            min = i
        }
    }
    return min;
}

int main() {
    int n;
    printf("Nhap so luong phan tu trong mang: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Khong hop le!!");
        return 1;
    }
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Khong hop le!!");
            return 1;
        }
    }
    int min = minFirstNumber(arr, n);
    printf("\nPhan tu nho nhat dau tien trong mang la %d, tai vi tri: %d\n", arr[min], min);
    return 0;
}