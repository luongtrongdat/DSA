#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[100];
    int age;
};
int main() {
    struct Student student[5];
    for (int i = 0; i < 5; i++) {
        students[i].id = i + 1;
        printf("Nhap ten cua nguoi thu %d: ", i + 1);
        fgets(students[i].name, 100, stdin);
        students[i].name[strlen(students[i].name) - 1] = '\0';
        printf("Nhap tuoi nguoi thu %d:  ", i + 1);
        scanf("%d", &students[i].age);
        fflush(stdin);
    }
    int findId;
    printf("Nhap id can tim: ");
    scanf("%d", &findId);
    for (int i = 0; i < 5; i++) {
        if (students[i].id == findId) {
            printf("{id: %d, name: \"%s\", age: %d}", students[i].id, students[i].name, students[i].age);
            return 0;
        }
    }
    printf("Khong tim thay id");
    return 0;
}