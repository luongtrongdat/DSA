#include <stdio.h>

void countNum(int num, int i) {
    if (i == num) {
        printf("%d", num);
        return;
    }
    printf("%d", i);
    return countNum(num, i + 1);
}
int main() {
    int num;
    printf("Moi nhap so can dem den: ");
    scanf("%d", &num);
    if (num <= 0) {
        printf("Gia tri khong hop le");
    } else {
        countNum(num, 1);
    }
    return 0;
}