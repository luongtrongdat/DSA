#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxCount = 0;
    int maxItem = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
               count++;
            }
        }
        if (count > maxCount) {
           maxCount = count;
           maxItem = arr[i];
        }
    }
    printf("Phan tu xuat hien nhieu nhat la: %d", maxItem);
    return 0;
}
// Độ phưc tạp thời gian: O(n^2)
// Độ phức tạp không gian: O(1)