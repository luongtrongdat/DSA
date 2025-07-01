#include <stdio.h>
void search(int *arr,int n,int findNum) {
    for(int i=0;i<n;i++) {
        if(arr[i]==findNum) {
            printf("Vi tri xuat hien thu: %d",i+1);
            return;
        }
    }
    printf("Khong tim thay phan tu");
}
//Do phuc tap thoi gan o(n)
int main() {
    int n,findNum;
    printf("Nhap vao so phan tu: ");
    scanf("%d", &n);
    if(n<=0||n>1000) {
        printf("Gia tri khong hop le");
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap vao phan tu co index [%d]: ",i);
        scanf("%d", &arr[i]);
    }
    printf("Nhap vao so can kiem tra: ");
    scanf("%d", &findNum);
    search(arr,n,findNum);
    return 0;
}