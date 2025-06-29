#include <stdio.h>

int sum(int arr[], int n) {
    if (n == 0) {
        return arr[0];
    }
    return arr[n] + sum(arr, n-1);
}
int main() {
    int n;
    printf("Nhap do dai mang: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Gia tri khong hop le");
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap vao gia tri tai [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Tong chuoi la: %d", sum(arr, n - 1));
    return 0;
}