#include <stdio.h>
#include <stdlib.h>

typedef struct Fila {
    int * v;
    int inicio;
    int fim;
    int max;
} Fila;

Fila * newFila(int max) {
    Fila * fila = (Fila *)malloc(sizeof(Fila));
    fila->v = (int *)calloc(max, sizeof(int));
    fila->max = max;
    fila->inicio = 0;
    fila->fim = 0;
    return fila;
}

int estaVazia(Fila * fila) {
    return fila->inicio == fila->fim;
}

void adicionar(Fila * fila, int valor) {
    fila->v[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->max;
    if(fila->fim == fila->inicio) {
        printf("Fila cheia.\n");
        exit(1);
    }
}

int remover(Fila * fila) {
    if(estaVazia(fila)) {
        printf("Fila vazia.\n");
        exit(1);
    }
    int valor = fila->v[fila->inicio];
    fila->v[fila->inicio] = 0;
    fila->inicio = (fila->inicio + 1) % fila->max;
    return valor;
}

int size(Fila * fila) {
    if((fila->inicio) < (fila->fim)) {
        return (fila->fim) - (fila->inicio);
    } else {
        return (fila->fim) - (fila->inicio) + (fila->max);
    }
}

void printFila(Fila * fila) {
    printf("[");
    for(int i = 0; i < fila->max; i++) {
        printf("%d", fila->v[i]);
        if(i < fila->max - 1) {
            printf(",");
        }
    }
    printf("](%d)\n", size(fila));
}

int main() {
    Fila * fila = newFila(5);
    adicionar(fila, 1);
    printFila(fila);
    adicionar(fila, 2);
    printFila(fila);
    adicionar(fila, 3);
    printFila(fila);
    adicionar(fila, 4);
    printFila(fila);
    remover(fila);
    printFila(fila);
    remover(fila);
    printFila(fila);
    remover(fila);
    printFila(fila);
    remover(fila);
    printFila(fila);
}