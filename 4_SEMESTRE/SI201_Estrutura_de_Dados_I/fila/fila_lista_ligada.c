#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No * proximo;
} No;

typedef struct Fila {
    No * inicio;
    No * fim;
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
    fila->fim = NULL;
    return fila;
}

int filaEstaVazia(Fila * fila) {
    return fila->inicio == NULL;
}

void adicionarFila(Fila * fila, int valor) {
    No * no = newNo(valor);
    if(filaEstaVazia(fila)) {
        fila->inicio = no;
        fila->fim = no;
    } else {
        fila->fim->proximo = no;
        fila->fim = no;
    }
}

int removerFila(Fila * fila) {
    if(filaEstaVazia(fila)) {
        printf("Fila vazia.\n");
        exit(1);
    }
    No * aux = fila->inicio;
    int valor = aux->valor;
    if(fila->inicio == fila->fim) {
        fila->inicio = NULL;
        fila->fim = NULL;
    } else {
        fila->inicio = fila->inicio->proximo;
    }

    free(aux);
    return valor;
}

int size(Fila * fila) {
    int size = 0;
    No * contador = fila->inicio;
    while(contador!= NULL) {
        contador = contador->proximo;
        size++;
    }
    return size;
}

int printFila(Fila * fila) {
    No * contador = fila->inicio;
    printf("[");
    while(contador != NULL) {
        printf("%d", contador->valor);
        contador = contador->proximo;
        if(contador != NULL) {
            printf("->");
        }
    }
    printf("](%d)\n", size(fila));
}

int main() {
    Fila * fila = newFila();
    adicionarFila(fila, 1);
    adicionarFila(fila, 2);
    adicionarFila(fila, 3);
    adicionarFila(fila, 4);
    adicionarFila(fila, 5);
    printFila(fila);
    removerFila(fila);
    printFila(fila);
    removerFila(fila);
    printFila(fila);
    removerFila(fila);
    printFila(fila);
}