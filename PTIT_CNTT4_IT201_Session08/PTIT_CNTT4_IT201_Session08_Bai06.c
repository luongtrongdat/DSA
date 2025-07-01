//
// Created by Windows on 01/07/2025.
//
#include <stdio.h>
void merge(int arr[], int low, int mid, int high) {
    int i,j,k,n1=mid-low+1,n2=high-mid,arrLow[n1],arrHigh[n2];
    for (i=0; i<n1; i++) {
        arrLow[i]=arr[low+i];
    }
    for (j=0; j<n2; j++) {
        arrHigh[j]=arr[mid+1+j];
    }
    i=0,j=0,k=low;
    while (i<n1 && j<n2) {
        if (arrLow[i]<=arrHigh[j]) {
            arr[k++]=arrLow[i++];
        }else {
            arr[k++]=arrHigh[j++];
        }
    }
    while (i<n1) {
        arr[k++]=arrLow[i++];
    }
    while (j<n2) {
        arr[k++]=arrHigh[j++];
    }
}
void sort(int arr[], int low, int high) {
    if (low < high) {
        int mid=(low+high)/2;
        sort(arr, low, mid);
        sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}
//Do phuc tap thoi gian o(n log n)
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