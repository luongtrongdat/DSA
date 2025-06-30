#include <ctype.h>
#include <stdio.h>
#include <string.h>

void sortStr(char *str, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tolower(str[j]) > tolower(str[j + 1])) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}
int main() {
    char str[100];
    printf("Nhap chuoi chu cai: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
    if (!strlen(str)) {
        printf("Ban chua nhap vao chuoi");
        return 0;
    }
    for (int i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i])) {
            printf("Chuoi khong hop le");
            return 0;
        }
    }
    sortStr(str, strlen(str));
    printf("Chuoi: %s\n", str);
    return 0;
}