#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No * proximo;
} No;

typedef struct Fila {
    No * inicio;
} Fila;

No * newNo(int valor) {
    No * no = (No *)malloc(sizeof(No));
    no->valor = valor;
    no->proximo = NULL;
    return no;
}

Fila * newFila() {
    Fila * fila = (Fila *)malloc(sizeof(Fila));
    fila->inicio = NULL;
    return fila;
}

int estaVazia(Fila * fila) {
    return fila->inicio == NULL;
}

int size(Fila * fila) {
    int size = 0;
    No * aux = fila->inicio;
    while(aux != NULL) {
        aux = aux->proximo;
        size++;
    }
    return size;
}

void adicionar(Fila * fila, int valor) {
    No * no = newNo(valor);
    if(estaVazia(fila)) {
        fila->inicio = no;
    } else {
        No * aux = fila->inicio;
        while(aux->proximo != NULL) {
            aux = aux->proximo;
        }
        aux->proximo = no;
    }
}

int remover(Fila * fila) {
    if(estaVazia(fila)) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    int valor = fila->inicio->valor;
    No * no = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    free(no);
    return valor;
}

void printFila(Fila * fila) {
    No * aux = fila->inicio;
    printf("[");
    while(aux != NULL) {
        printf("%d", aux->valor);
        aux = aux->proximo;
        if(aux != NULL) {
            printf(",");
        }
    }
    printf("](%d)\n", size(fila));
}

int main() {
    Fila * fila = newFila();
    adicionar(fila, 1);printFila(fila);
    adicionar(fila, 2);printFila(fila);
    adicionar(fila, 3);printFila(fila);
    adicionar(fila, 4);printFila(fila);
    adicionar(fila, 5);printFila(fila);
    remover(fila);printFila(fila);
    remover(fila);printFila(fila);
    remover(fila);printFila(fila);
    remover(fila);printFila(fila);
    remover(fila);printFila(fila);
}