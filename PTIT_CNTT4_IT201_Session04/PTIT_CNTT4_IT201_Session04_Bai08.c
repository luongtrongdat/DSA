#include <stdio.h>

int main() {
    int n;
    int check = 1;
    int findNum;
    printf("Nhap so phan tu: ");
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
    for (int i = 0; i < n; i++) {
        if (arr[i] == findNum) {
            printf("%d, ",i);
            check = 0;
        }
    }
    if (check) {
        printf("Khong co phan tu trong mang");
    }
    return 0;
}