#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
    int * v;
    int max;
    int top;
} Pilha;

Pilha * newPilha(int max) {
    Pilha * p = (Pilha *)malloc(sizeof(Pilha));
    p->v = (int *)malloc(sizeof(int) * max);
    p->max = max;
    p->top = 0;
    return p;
}

void adicionar(Pilha * p, int valor) {
    if(p->top == p->max) {
        printf("Pilha cheia.\n");
        exit(1);
    }
    p->v[p->top++] = valor;
}

int remover(Pilha * p) {
    if(p->top == 0) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    p->top--;
    return p->v[p->top];
}

int estaVazia(Pilha * p) {
    return p->top == 0;
}

int size(Pilha * p) {
    return p->top;
}

void printPilha(Pilha * p) {
    printf("[");
    for(int i = p->top - 1; i >= 0; i--) {
        printf("%d", p->v[i]);
        if(i > 0) {
            printf("<-");
        }
    }
    printf("]\n");
}

int main() {
    Pilha * p = newPilha(10);
    adicionar(p, 1);
    adicionar(p, 2);
    adicionar(p, 3);
    adicionar(p, 4);
    adicionar(p, 5);
    adicionar(p, 6);
    printPilha(p);
    remover(p);
    remover(p);
    remover(p);
    remover(p);
    printPilha(p);
    remover(p);
    remover(p);
    printPilha(p);
}