#include <stdio.h>

int way(int steps, int nowStep) {
    if (nowStep > steps) {
        return 0;
    }
    if (nowStep == steps) {
        return 1;
    }
    return way(steps, nowStep + 1) + way(steps, nowStep + 2);
}
int main() {
    int steps;
    printf("Nhap so bac thang: ");
    scanf("%d", &steps);
    printf("Co %d cach di het bac thang: ");
    return 0;
}