#include <stdio.h>

int totalNum(int num) {
    if (num / 10 == 0 && num % 10 == 0) {
        return 0;
    }
    return num % 10 + totalNum(num / 10);
}
int main() {
    int num;
    printf("Moi nhap so nguyen duong:");
    scanf("%d", &num);
    if (num < 0) {
        printf("Gia tri khong hop le");
        return 0;
    }
    printf("Tong cac chu so la %d", totalNum(num));
    return 0;
}