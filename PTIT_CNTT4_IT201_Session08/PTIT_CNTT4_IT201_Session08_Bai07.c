#include <stdio.h>
int partition(int *arr,int low,int high) {
    int pivot = arr[high],i = low-1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}
void sort(int *arr,int low,int high) {
    if (low < high) {
        int pivot = partition(arr,low,high);
        sort(arr,low,pivot-1);
        sort(arr,pivot+1,high);
    }
}
//Do phuc tap thoi gian o(n^2) hoac o(n log n)
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
    sort(arr,0,n-1);
    printf("\nMang sap xep: ");
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}