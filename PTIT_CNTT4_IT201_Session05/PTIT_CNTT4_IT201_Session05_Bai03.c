#include <stdio.h>

int factorial(int num) {
    if (num == 1) {
        return 1;
    }
    return num * factorial(num - 1);
}
int main() {
    int num;
    printf("Moi nhap so can tinh giai thua: ");
    scanf("%d", &num);
    if (num <= 0) {
        printf("Gia tri khong hop le");
    } else {
        printf("Giai thua cua %d la: %d", num, factorial(num));
    }
    return 0;
}