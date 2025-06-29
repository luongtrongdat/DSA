#include <stdio.h>
#include <string.h>

void numToBinary(int num, char str[]) {
    char result[2];
    if (num == 0) {
        return;
    }
    sprintf(result, "%d", num % 2);
    strcat(result, str);
    strcpy(str, result);
    numToBinary(num / 2, str);
}
int main() {
    int num;
    printf("Nhap so nguyen duong can doi sang nhi phan: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Gia tri khong hop le");
        return 0;
    }
    numToBinary(num, str);
    printf("%s, str");
    return 0;
}