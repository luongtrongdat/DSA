#include <stdio.h>

int count;
int tower(int n, char A, char B, char C) {
    if (n == 0) {
        return 0;
    }
    tower(n - 1, A, C, B);
    printf("Dia %d di chuyen tu %c sang %c\n", n, A, C);
    count++;
    tower(n - 1, A, B, C);
}
int main() {
    int n;
    printf("Nhap so luong dia: ");
    scanf("%d", &n);
    if (n == 1) {
        printf("Dia 1 di chuyen tu A sang C");
        return 0;
    }
    tower(n, 'A', 'B', 'C');
    printf("Tong cong %d buoc", count);
}