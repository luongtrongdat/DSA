#include <stdio.h>
#include <stdlib.h>

void fibonacci(int n, int arr[], int i) {
    if (i == n) {
        return;
    }
    if (i < 2) {
        if (i == 0) {
            arr[n - 1] = 0;
        }
        if (i == 1) {
            arr[n - 2] = 1;
        }
    } else {
        arr[n - i - 1] = arr[n - i] + arr[n - i + 1];
    }
    fibonacci(n, arr, i + 1);
}
int main() {
    int n;
    printf("Nhap so fibonacci can tim: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Gia tri khong hop le");
        return 0;
    }
    int arr[n];
    fibonacci(n, arr, 0);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}