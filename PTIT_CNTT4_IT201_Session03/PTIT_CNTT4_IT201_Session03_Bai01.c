#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Phan tu khong hop le");
        return 0;
    }
    int *arr=(int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: \n",i+1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d  la : %d", i+1,arr[i]);
    }
    free(arr);
    return 0;
}