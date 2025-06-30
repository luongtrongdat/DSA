#include <stdio.h>

void merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int arrLow[n1], arrHigh[n2];
    for (i = 0; i < n1; i++) {
        arrLow[i] = arr[low + i];
    }
    for (j = 0; j < n2; j++) {
        arrHigh[j] = arr[mid + 1 + j];
    }
    i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (arrLow[i] <= arrHigh[j]) {
            arr[k++] = arrLow[i++];
        } else {
            arr[k++] = arrHigh[j++];
        }
    }
    while (i < n1) {
        arr[k++] = arrLow[i++];
    }
    while (j < n2) {
        arr[k++] = arrHigh[j++];
    }
}
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
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
    printf("Mang ban dau: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    printf("\nMang sau khi sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}