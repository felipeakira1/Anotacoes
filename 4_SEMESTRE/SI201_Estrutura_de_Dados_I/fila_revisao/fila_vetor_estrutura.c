#include <stdio.h>
#include <stdlib.h>

typedef struct Fila {
    int * v;
    int maximo;
    int inicio;
    int fim;
} Fila;

Fila * newFila(int maximo) {
    Fila * fila = (Fila *)malloc(sizeof(Fila));
    fila->v = (int *)calloc(maximo, sizeof(int));
    fila->maximo = maximo;
    fila->inicio = 0;
    fila->fim = 0;
    return fila;
}

int estaVazia(Fila * fila) {
    return fila->inicio == fila->fim;
}

void adicionar(Fila * fila, int valor) {
    fila->v[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->maximo;
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
    fila->inicio = (fila->inicio + 1) % fila->maximo;
    return valor;
}

int size(Fila * fila) {
    if(fila->fim > fila->inicio) {
        return fila->fim - fila->inicio;
    } else {
        return fila->fim - fila->inicio + fila->maximo;
    }
}

void printFila(Fila * fila) {
    printf("[");
    for(int i = 0; i < fila->maximo; i++) {
        printf("%d", fila->v[i]);
        if(i < fila->maximo - 1) {
            printf(",");
        }
    }
    printf("]");
    printf("(%d)\n", size(fila));
}

int main() {
    Fila * f = newFila(5);
    adicionar(f,100);printFila(f);
    adicionar(f,200);printFila(f);
    adicionar(f,300);printFila(f);
    adicionar(f,400);printFila(f);
    remover(f);printFila(f);
    remover(f);printFila(f);
    remover(f);printFila(f);
    adicionar(f,500);printFila(f);
    adicionar(f,600);printFila(f);
}