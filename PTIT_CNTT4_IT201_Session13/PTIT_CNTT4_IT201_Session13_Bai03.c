#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *data;
    int top;
    int size;
}Stack;
Stack *createStack(int size) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    s->size = size;
    s->data=(int *)malloc(size*sizeof(int));
    return s;
}
void push(Stack *s, int data) {
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
    printf("%d\n",s->data[s->top--]);
}
int main() {
    int n,x;
    printf("Nhap vao so phan tu: ");
    scanf("%d", &n);
    if (n<=0||n>5) {
        printf("Gia tri khong hop le");
        return 0;
    }
    Stack *s = createStack(n);
    for (int i=1; i<=n; i++) {
        printf("Nhap vao gia tri phan tu: ");
        scanf("%d", &x);
        push(s, x);
    }
    pop(s);
    pop(s);
    free(s->data);
    free(s);
    return 0;
}