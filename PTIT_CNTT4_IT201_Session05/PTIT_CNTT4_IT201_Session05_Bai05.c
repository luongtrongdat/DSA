#include <stdio.h>
#include <string.h>

int palindrome(int i, char str[]) {
    if (i == strlen(str)/2) {
        return 1;
    }
    if (str[i] == str[strlen(str)-i-1]) {
        return palindrome(i + 1, str);
    }
    return 0;
}
int main() {
    char str[50];
    printf("Nhap vao chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    if (!strlen(str)) {
        printf("Ban khong nhap vao chuoi");
    } else {
        if (palindrome(0, str)) {
            printf("Chuoi doi xung");
        } else {
            printf("Chuoi khong doi xung");
        }
    }
    return 0;
}
