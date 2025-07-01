#include <stdio.h>
void search(int arr[],int n,int findNum) {
    int left = 0,right = n-1,mid;
    while(left<=right) {
        mid = (left+right)/2;
        if(arr[mid]==findNum) {
            printf("Vi tri xuat hien thu: %d",mid+1);
            return;
        }else if(arr[mid]>findNum) {
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    printf("Khong tim thay phan tu");
}
//Do phuc tap thoi gian o(log n)
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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Nhap vao so can kiem tra: ");
    scanf("%d", &findNum);
    search(arr,n,findNum);
    return 0;
}