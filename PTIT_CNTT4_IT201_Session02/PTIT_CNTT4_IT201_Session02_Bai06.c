#include <stdio.h>

void addCharacter(int arr[], int n) {
    int pos;
    printf("Nhap vi tri muon them: ");
    scanf("%d", &pos);
    if (pos > n - 1) {
        printf("Khong hop le");
        return;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    n++;
    int value;
    printf("Nhap vi tri muon them: ");
    scanf("%d", &value);
    arr[pos] = value;
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
}
int main() {
    int n;
    int arr[100];
    printf("Nhap phan tu trong mang (0 < n <= 100): ");
    scanf("%d", &n);
    if (n > 0 && n <= 100) {
       for (int i = 0; i < n; i++) {
            printf("Nhap phan tu thu %d: ", i + 1);
            scanf("%d", &arr[i]);
       }
       addCharacter(arr, n);
    } else {
       printf("Gia tri khong hop le");
    }
    return 0;
}