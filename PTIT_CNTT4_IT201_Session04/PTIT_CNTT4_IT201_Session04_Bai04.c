#include <stdio.h>

int main() {
    int n;
    int findNum;
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
    printf("Nhap vao so can tim: ");
    scanf("%d", &findNum);
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == findNum) {
            index = i;
        }
    }
    if (index == -1) {
        printf("Khong tim thay phan tu.");
        return 0;
    }
    printf("Chi so phan tu cuoi cung trong mang la: %d", index);
    return 0;
}