#include <stdio.h>
#define MAX 10

int v[MAX];
int top = 0;

void adicionar(int valor) {
    v[top++] = valor;
}

int remover() {
    return v[--top];
}

int main() {
    adicionar(1);
    adicionar(2);
    printf("Elemento removido %d\n", remover());
    printf("Elemento removido %d", remover());
}