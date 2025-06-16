#include <stdio.h>

// cách 1:
int main() {
    int arr[10] = {0, 17, 24, 14, 23, 10, 2, 4, 7, 5};
    int flag = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (arr[i] == arr[j]) {
               flag =1;
               break;
            }
        }
        if (flag == 1) {
           break;
        }
    }
    if (flag == 1) {
       printf("Co phan tu trung lap");
    } else {
       printf("Khong co phan tu trung lap");
    }
return 0;
}
// Độ phưc tạp thời gian: O(n^2)
// Độ phức tạp không gian: O(1)


//cách 2:
int main() {
    int arr[] = {10, 99, 100, 999, 21, 0, 24};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count[1001] = {0};
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (count[arr[i]] > 0) {
           flag = 1;
           break;
        }
        count[arr[i]]++;
    }
    if (flag == 1) {
       printf("Co phan tu trung lap");
    } else {
       printf("Khong co phan tu trung lap");
    }
    return 0;
}
// Độ phưc tạp thời gian: O(n)
// Độ phức tạp không gian: O(1)
