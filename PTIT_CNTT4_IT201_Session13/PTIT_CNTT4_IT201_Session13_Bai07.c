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
        return;
    }
    for (int i=s->top; i>=0; i--) {
        printf("%c",s->data[i]);
    }
    printf("\n");
}
void bracket(Stack *s) {
    int firstCheck=0,secondCheck=0,thirdCheck=0;
    for (int i=s->top;i>=0;i--) {
        if (s->data[i]==')') {
            if (firstCheck==1) {
                printf("False\n");
                return;
            }
            firstCheck=1;
        }
        if (s->data[i]=='('&&firstCheck==1) {
            firstCheck=0;
        }else if (s->data[i]=='('&&firstCheck==0) {
            printf("False\n");
            return;
        }
        if (s->data[i]==']'&&firstCheck==0) {
            if (secondCheck==1) {
                printf("False\n");
                return;
            }
            secondCheck=1;
        }
        if (s->data[i]=='['&&secondCheck==1&&firstCheck==0) {
            secondCheck=0;
        }else if (s->data[i]=='['&&(secondCheck==0||firstCheck==1)) {
            printf("False\n");
            return;
        }
        if (s->data[i]=='}'&&secondCheck==0) {
            if (thirdCheck==1) {
                printf("False\n");
                return;
            }
            thirdCheck=1;
        }
        if (s->data[i]=='{'&&thirdCheck==1&&secondCheck==0&&firstCheck==0) {
            thirdCheck=0;
        }else if (s->data[i]=='{'&&(thirdCheck==0||secondCheck==1||firstCheck==1)) {
            printf("False\n");
            return;
        }
    }
    printf("True\n");
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
    bracket(s);
    printStack(s);
    free(s->data);
    free(s);
    return 0;
}