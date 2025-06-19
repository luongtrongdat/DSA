#include <stdio.h>

void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
int main() {
    int n;
    int arr[100];
    printf("Nhap so phan tu trong mang (0 < n <= 100): ");
    scanf("%d", &n);
    if (n > 0 && n <= 100) {
        for (int i = 0; i < n; i++) {
             printf("Nhap phan tu thu %d: ", i + 1);
             scanf("%d", &arr[i]);
        }
        reverseArray(arr, n);
    } else {
        printf("Gia tri khong hop le");
    }
    return 0;
}