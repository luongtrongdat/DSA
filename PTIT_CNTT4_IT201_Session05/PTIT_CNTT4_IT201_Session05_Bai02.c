#include <stdio.h>

int sumNum(int num) {
    if (num == 0) {
        return 0;
    } else {
        return num + sumNum(num - 1);
    }
}
int main() {
    int num;
    printf("Moi nhap so can tinh tong den: ");
    scanf("%d", &num);
    if (num <= 0) {
        printf("Gia tri khong hop le");
    } else {
        printf("Tong tu 1 den %d la: %d", num, sumNum(num));
    }
    return 0;
}