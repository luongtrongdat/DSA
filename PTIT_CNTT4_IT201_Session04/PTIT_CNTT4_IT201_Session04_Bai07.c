#include <stdio.h>

int main() {
    int n;
    int check = 1;
    printf("Nhap vao so phan tu: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Khong hop le!!");
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n / 2; i++) {
        if (arr[i] == arr[n - i - 1]) {
            printf("Cap doi xung: (%d,%d)", arr[i], arr[n - i - 1]);
            check = 0;
        }
    }
    if (check) {
        printf("Khong co cap doi xung");
    }
    return 0;
}