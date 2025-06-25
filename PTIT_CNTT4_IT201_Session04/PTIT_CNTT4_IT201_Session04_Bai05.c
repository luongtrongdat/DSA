#include <stdio.h>
#include <stdlib.h>

int compareIntegers(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int binarySearch(int arr[], int size, int value) {
    int left =0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            return mid;
        }
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compareIntegers);
    printf("\nMang sau khi sap xep:\n");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
    int searchValue;
    printf("\nNhap gia tri can tim: ");
    scanf("%d", &searchValue);
    int result = binarySearch(arr, n, searchValue);
    if (result != 1) {
        printf("Phan tu co trong mang", searchValue, result);
    } else {
        printf("Khong tim thay trong mang", searchValue);
    }
    return 0;
}