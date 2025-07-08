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
int main() {
    int n;
    printf("Nhap vao so phan tu: ");
    scanf("%d", &n);
    if (n<=0||n>5) {
        printf("Gia tri khong hop le");
        return 0;
    }
    Stack *s = createStack(n);
    free(s->data);
    free(s);
    return 0;
}