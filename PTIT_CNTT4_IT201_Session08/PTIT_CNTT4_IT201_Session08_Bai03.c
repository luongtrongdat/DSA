#include <stdio.h>
void sort(int *arr,int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j]>arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
//Do phuc tap thoi gian o(n^2)
int main() {
    int n;
    printf("Nhap vao so luong phan tu: ");
    scanf("%d",&n);
    if(n<=0||n>1000) {
        printf("Gia tri khong hop le");
        return 0;
    }
    int arr[n];
    for(int i=0;i<n;i++) {
        printf("Nhap phan tu co index la [%d]: ",i);
        scanf("%d",&arr[i]);
    }
    printf("Mang ban dau: ");
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    sort(arr,n);
    printf("\nMang sap xep: ");
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}