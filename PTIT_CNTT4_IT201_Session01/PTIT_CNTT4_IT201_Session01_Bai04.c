#include <stdio.h>

// cách 1:
int sumLoop(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}
// Độ phức tạp thời gian: O(n)

//cách 2:
int sumLoop(int n) {
    if (n < 1) {
       return 0;
    }
    return (int)n * (n + 1) / 2;
//Độ phức tạp thời gian: O(1)