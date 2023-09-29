#include <stdio.h>
#define MAX 100

int top = 0;
int v[MAX];

void push(int valor) {
    v[top++] = valor;
}

int pop() {
    return v[--top];
}

int main() {
    push(3);
    push(4);
    printf("%d\n", pop());
}