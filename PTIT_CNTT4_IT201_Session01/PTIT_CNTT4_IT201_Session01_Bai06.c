#include <stdio.h>

int countCurren(int arr[], int n, int a) {
    int count = 0;
    for (int i = 0, i < n; i++) {
        if (arr[i] == a) {
           count++;
        }
    }
    return count;
}
//Độ phức tạp thời gian: O(n)