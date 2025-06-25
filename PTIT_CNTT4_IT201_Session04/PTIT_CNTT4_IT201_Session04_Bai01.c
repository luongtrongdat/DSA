#include <stdio.h>

int linearSearch(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}
int main() {
    int n;
    printf("Nhap so luong phan tu trong mang: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Khong hop le!!");
        return 1;
    }
    int arr[n];
    printf("Nhap cac phan tu trong mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Khong hop le!!");
            return 1;
        }
    }
    int searchValue;
    printf("\n Nhap gia tri can tim: ");
    if (scanf("%d", &searchValue) != 1) {
        printf("Khong hop le!!");
        return 1;
    }
    int foundIndex = linearSearch(arr, n, searchValue);
    if (foundIndex == -1) {
        printf("Tim thay gia tri %d tai vi tri: %d\n", searchValue, foundIndex);
    } else {
        printf("Khong tim thay phan tu");
    }
    return 0;
}