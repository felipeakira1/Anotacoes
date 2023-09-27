#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No * proximo;
} No;

typedef struct Pilha {
    No * top;
} Pilha;

No * newNo(int valor) {
    No * no = (No *)malloc(sizeof(No));
    no->valor = valor;
    no->proximo = NULL;
    return no;
}

Pilha * newPilha() {
    Pilha * p = (Pilha *)malloc(sizeof(Pilha));
    p->top = NULL;
    return p;
}

void push(Pilha * pilha, int valor) {
    No * no = newNo(valor);
    no->proximo = pilha->top;
    pilha->top = no;
}

int pop(Pilha * pilha) {
    if(pilha->top == NULL) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    int valor = pilha->top->valor;
    No * no = pilha->top;
    pilha->top = pilha->top->proximo;
    free(no);
    return valor;
}

int size(Pilha * pilha) {
    No * aux = pilha->top;
    int size = 0;
    while(aux != NULL) {
        aux = aux->proximo;
        size++;
    }
    return size;
}

void printPilha(Pilha * pilha) {
    No * aux = pilha->top;
    printf("[");
    while(aux != NULL) {
        printf("%d", aux->valor);
        aux = aux->proximo;
        if(aux != NULL) {
            printf("<-");
        }
    }
    printf("](%d)\n", size(pilha));
}

int main() {
    Pilha * pilha = newPilha();
    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 3);
    push(pilha, 4);
    push(pilha, 5);
    printPilha(pilha);
    pop(pilha);
    pop(pilha);
    pop(pilha);
    pop(pilha);
    pop(pilha);
    printPilha(pilha);
}