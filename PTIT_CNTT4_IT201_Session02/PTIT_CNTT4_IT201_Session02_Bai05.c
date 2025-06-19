#include <stdio.h>

void deleteCharacter(int arr[], int n) {
    int pos;
    printf("Nhap vi tri muon xoa: ");
    scanf("%d", &pos);
    if (pos > n - 1) {
        printf("Khong hop le");
        return;
    }
    for (int i = pos; i < n; i++) {
        arr[i] = arr[i + 1];
    }
    n--
    printf("Mang sau khi xoa: \n");
    for (int i = 0; i < n; i++) {
        printf("%d",  arr[i]);
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
        deleteCharacter(arr, n);
    } else {
        printf("Gia tri khong hop le");
    }
    return 0;
}
