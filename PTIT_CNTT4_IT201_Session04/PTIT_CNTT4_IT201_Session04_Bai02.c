#include <stdio.h>

int maxFirstNumber(int arr[], int size) {
    if (size <= 0) {
        return -1;
    }
    int max = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[max]) {
            max = i;
        }
    }
    return max;
}

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
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
    int max = maxFirstNumber(arr, n);
    printf("\n Phan tu lon nhat dau tien trong mang la %d, tai vi tri: %d\n", arr[max], max);
    return 0;
}