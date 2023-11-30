#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
    int top;
    int max;
    int * v;
} Pilha;

Pilha * newPilha(int max) {
    Pilha * aux = (Pilha *)malloc(sizeof(Pilha));
    aux->top = 0;
    aux->max = max;
    aux->v = (int *)malloc(sizeof(int) * max);
}

void push(Pilha * pilha, int valor) {
    if(pilha->top == pilha->max) {
        printf("Pilha cheia.\n");
        exit(1);
    }
    pilha->v[pilha->top++] = valor;
}

int pop(Pilha * pilha) {
    if(pilha->top == 0) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    pilha->top--;
    return pilha->v[pilha->top];
}

void printPilha(Pilha *p) {
    printf("(");
    for (int i = p->top - 1; i >= 0; i--) {
        printf("%d", p->v[i]);
        if (i > 0) {
            printf("<-");
        }
    }
    printf(")\n");
}

int main() {
    Pilha * pilha = newPilha(10);
    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 3);
    push(pilha, 4);
    push(pilha, 5);
    printPilha(pilha);
    pop(pilha);
    printPilha(pilha);
    pop(pilha);
    printPilha(pilha);
    pop(pilha);
    printPilha(pilha);
}