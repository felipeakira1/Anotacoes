#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor;
    struct No * proximo;
} No;

No * newNo(char valor) {
    No * no = (No *)malloc(sizeof(No));
    no->valor = valor;
    no->proximo = NULL;
    return no;
}

typedef struct Pilha {
    No * topo;
} Pilha;

Pilha * newPilha() {
    Pilha * p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void push(Pilha * p, int valor) {
    No * no = newNo(valor);
    no->proximo = p->topo;
    p->topo = no;
}

char pop(Pilha * p) {
    if(p->topo == NULL) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    char valor = p->topo->valor;
    No * no = p->topo;
    p->topo = p->topo->proximo;
    free(no);
    return valor;
}

int size(Pilha * p) {
    int size = 0;
    No * aux = p->topo;
    while(aux->proximo != NULL) {
        aux = aux->proximo;
        size++;
    }
    return size;
}

void printPilha(Pilha * p) {
    printf("(");
    No * aux = p->topo;
    while(aux != NULL) {
        printf("%c", aux->valor);
        aux = aux->proximo;
        if(aux != NULL) {
            printf("<-");
        }
    }
    printf(")[%c]\n", size(p));
}

int main() {
    Pilha * pilha = newPilha();
    char palavra[10];
    printf("Digita uma palavra: ");
    scanf("%s", &palavra);
    int tamanho = strlen(palavra);

    for(int i = 0; i < tamanho; i++) {
        push(pilha, palavra[i]);
    }

    printf("Palavra invertida: ");
    while(pilha->topo != NULL) {
        printf("%c", pop(pilha));
    }
    printf("\n");
}