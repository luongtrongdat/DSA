#include <stdio.h>

void findmax(int arr[], int n) {
     int max = arr[0];
     for (int i = 0; i < n; i++) {
         if (arr[i] > max) {
            max = arr[i];
         }
     }
     printf("Phan tu co gia tri lon nhat la: %d", max);
}

int main() {
    int n;
    int arr[100];
    printf("Nhap so pan tu trong mang (0 < n <= 100): ");
    scanf("%d", &n);
    if (n > 0 && n <= 100) {
       for (int i = 0; i < n; i++) {
           printf("Nhap phan tu thu %d: ", i + 1);
           scanf("%d", &arr[i]);
       }
       findmax(arr, n);
    } else {
       printf("Gia tri khong hop le");
    }
    return 0;
}