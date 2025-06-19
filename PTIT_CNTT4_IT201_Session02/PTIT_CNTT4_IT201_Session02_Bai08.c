#include <stdio.h>

void biggerCharacter(int arr[], int n) {
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[i + 1]) {
            printf("%d \n", arr[i]);
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("Khong co phan tu nao");
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
        biggerCharacter(arr, n);
    } else {
        printf("Gia tri khong hop le");
    }
    return 0;
}