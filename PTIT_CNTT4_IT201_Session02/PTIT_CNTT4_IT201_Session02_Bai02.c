#include <stdio.h>

void countOccurence(int arr[], int n) {
    int count = 0;
    int a;
    printf("Nhap gia tri can dem so lan xuat hien");
    scanf("%d", &a);
    for (int i = 0; i < n; i++) {
        if (arr[i] == a) {
            count++;
        }
    }
    printf("Phan tu %d xuat hien: %d lan", a, count);
}
int main() {
    int n;
    int arr[100];
    printf("Nhap so phan tu trong mang (0 < n <= 100): ");
    scanf("%d", &n);
    if(n > 0 && n <= 100) {
        for (int i = 0; i < n; i++) {
             printf("Nhap phan tu thu %d: ", i + 1);
             scanf("%d", &arr[i]);
        }
        countOccurence(arr, n);
    } else {
        printf("Gia tri khong hop le");
    }
    return 0;
}

