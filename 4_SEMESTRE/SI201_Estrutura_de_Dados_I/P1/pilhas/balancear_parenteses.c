#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pilha {
    int * v;
    int topo;
    int maximo;
} Pilha;

Pilha * newPilha(int maximo) {
    Pilha * pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->v = (int *)calloc(maximo, sizeof(int));
    pilha->topo = 0;
    pilha->maximo = maximo;
}

void adicionar(Pilha * pilha, int valor) {
    if(pilha->topo == pilha->maximo) {
        printf("Pilha cheia.\n");
        exit(1);
    }
    pilha->v[pilha->topo++] = valor;
}

int remover(Pilha * pilha) {
    if(pilha->topo == 0) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    pilha->topo--;
    int valor = pilha->v[pilha->topo];
    pilha->v[pilha->topo] = 0;
    return valor;
}

int estaVazia(Pilha * pilha) {
    return pilha->topo == 0;
}

int size(Pilha * pilha) {
    return pilha->topo;
}

int balanceado(char * texto) {
    int size;
    size = strlen(texto);
    Pilha * p = newPilha(size);
    for(int i = 0; i < size; i++) {
        if(texto[i] == '(') {
            adicionar(p, 1);
        }
        if(texto[i] == ')') {
            if(estaVazia(p)) {
                return 0;
            }
            remover(p);
        }
    }
    return estaVazia(p);
}
void printPilha(Pilha * pilha) {
    printf("(");
    for(int i = 0; i < pilha->maximo; i++) {
        printf("%d", pilha->v[i]);
        if(i < pilha->maximo - 1) {
            printf("<-");
        }
    }
    printf(")(%d)\n",size(pilha));
}

int main() {
    char texto[100];
    strcpy(texto, "((2+2) * 2) + (2 + 2)");
    printf("%s balanceado =  %d\n", texto, balanceado(texto));
    strcpy(texto, "(()");
    printf("%s balanceado =  %d\n", texto, balanceado(texto));
    strcpy(texto, "())");
    printf("%s balanceado =  %d\n", texto, balanceado(texto));
}