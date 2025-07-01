#include <stdio.h>
void insertionSort(int *arr,int low,int high) {
    for(int i=low+1;i<=high;i++) {
        int max = arr[i],j=i-1;
        while(j>=low && arr[j]>max) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=max;
    }
}
void linearSearch(int *arr,int n,int findNum) {
    for(int i=0;i<n;i++) {
        if(arr[i]==findNum) {
            printf("So can tim co index la %d ",i);
            return;
        }
    }
    printf("Khong tim thay");
}
void binarySearch(int *arr,int n,int findNum) {
    int low=0,high=n-1;
    while(low<=high) {
        int mid = (low+high)/2;
        if(arr[mid]==findNum) {
            printf("So can tim co index la %d ",mid);
            return;
        }
        else if(arr[mid]>findNum) {
            high = mid-1;
        }else {
            low = mid+1;
        }
    }
    printf("Khong tim thay");
}
void printArr(int *arr,int n) {
    printf("Mang: ");
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main() {
    int n,findNum;
    printf("Nhap vao so luong phan tu: ");
    scanf("%d", &n);
    if (n<=0 || n>1000) {
        printf("Gia tri khong hop le");
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap vao phan tu co index [%d]",i);
        scanf("%d", &arr[i]);
    }
    printArr(arr,n);
    printf("Nhap vao so can tim");
    scanf("%d", &findNum);
    linearSearch(arr,n,findNum);
    insertionSort(arr,0,n-1);
    binarySearch(arr,n,findNum);
    return 0;
}