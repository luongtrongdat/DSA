#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int top;
    int size;
}Stack;
Stack *createStack(int size) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    s->size = size;
    s->data=(char *)malloc(size*sizeof(char));
    return s;
}
void push(Stack *s, char data) {
    if (s->top==s->size-1) {
        printf("Stack day\n");
        return;
    }
    s->data[++s->top] = data;
}
void pop(Stack *s) {
    if (s->top==-1) {
        printf("Stack trong\n");
        return;
    }
    printf("%c",s->data[s->top--]);
}
void printStack(Stack *s) {
    if (s->top==-1) {
        printf("Stack trong\n");
    }
    for (int i=s->top; i>=0; i--) {
        printf("%c",s->data[i]);
    }
    printf("\n");
}
void symmetrical(Stack *s) {
    if (s->top==-1) {
        printf("Stack trong\n");
        return;
    }
    for (int i=0; i<=s->top/2; i++) {
        if (s->data[i]!=s->data[s->top-i]) {
            printf("Chuoi khong doi xung\n");
            return;
        }
    }
    printf("Chuoi doi xung\n");
}
int main() {
    char x[100];
    printf("Nhap vao chuoi: ");
    fflush(stdin);
    fgets(x, 100, stdin);
    x[strcspn(x, "\n")]='\0';
    Stack *s = createStack(strlen(x));
    for (int i=0; i<strlen(x); i++) {
        push(s, x[i]);
    }
    printStack(s);
    symmetrical(s);
    free(s->data);
    free(s);
    return 0;
}