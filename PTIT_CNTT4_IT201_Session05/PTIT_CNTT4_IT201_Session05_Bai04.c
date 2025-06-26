#include <stdio.h>

int sumAToB(int firstNum, int secondNum) {
    if (firstNum == secondNum) {
        return firstNum;
    } else {
        return secondNum + sumAToB(firstNum, secondNum - 1);
    }
}
int main() {
    int firstNum, secondNum;
    printf("Moi nhap so bat dau: ");
    scanf("%d", &firstNum);
    printf("Moi nhap so ket thuc: ");
    scanf("%d", &secondNum);
    if (firstNum <= 0 || secondNum <= 0) {
        printf("Gia tri khong hop le");
    } else {
        printf("Tong tu %d den %d la: %d", firstNum, secondNum, sumAToB(firstNum, secondNum));
    }
    return 0;
}