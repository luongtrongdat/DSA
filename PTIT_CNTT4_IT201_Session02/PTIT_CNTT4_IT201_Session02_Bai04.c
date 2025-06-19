#include <stdio.h>

void fixCharacter(int arr[], int n) {
    int pos = 0;
    printf("Nhap vi tri muon sua: ");
    scanf("%d", &pos);
    if (pos > n) {
        printf("Khong hop le");
        return;
    }
    int value;
    printf("Nhap gia tri can sua: ");
    scanf("%d", &value);
    for (int i = 0; i < n; i++) {
        if (i == pos) {
            arr[i] = value;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
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
        fixCharacter(arr, n);
    } else {
        printf("Gia tri khong hop le");
    }
    return 0;
}
