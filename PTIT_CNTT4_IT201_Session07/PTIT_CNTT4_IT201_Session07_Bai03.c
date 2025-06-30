#include <stdio.h>

void insertionSort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        int max = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > max) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = max;
    }
}
int main() {
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    if (n <= 0 || n > 1000) {
        printf("Gia tri khong hop le");
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu co chi so [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Mang ban dau:");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    insertionSort(arr, n);
    printf("\nMang sau khi sap xep");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
