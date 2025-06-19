#include <stdio.h>

void sumCharacter(int arr[], int n) {
    int sum = 0;
    printf("Tong cua cap so can tim la: ");
    scanf("%d", &sum);
    int flag = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] != arr[j] && arr[i] + arr[j] == sum) {
                printf("Cap so do la: %d va %d \n", arr[i], arr[j]);
                flag = 1;
            }
        }
    }
    if (flag == 0) {
        printf("Khong tim thay");
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
        sumCharacter(arr, n);
    } else {
        printf("Gia tri khong hop le");
    }
    return 0;
}