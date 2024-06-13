#include <stdio.h>
#define N 100

typedef struct {
    int top;
    int data[N];
} stack;

void push(stack *st, int item) {
    if (st->top == N) {
        printf("Stack is full\n");
        return;
    }
    st->data[st->top++] = item;
}

void pop(stack *st) {
    if (!st->top) {
        printf("Stack is empty\n");
        return;
    }
    st->top--;
}

int top(stack *st) {
    return st->data[st->top - 1];
}

int main() 
{
    stack st;
    st.top = 0;

    push(&st, 1);
    push(&st, 2);
    push(&st, 3);

    while (st.top) {
        printf("%d\n", top(&st));
        pop(&st);
    }
}