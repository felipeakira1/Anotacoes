#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pilha {
    char * v;
    int topo;
    int maximo;
} Pilha;

Pilha * newPilha(int maximo) {
    Pilha * pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->v = (char *)malloc(sizeof(char) * maximo);
    pilha->maximo = maximo;
    pilha->topo = 0;
}

void adicionar(Pilha * pilha, char valor) {
    if(pilha->topo == pilha->maximo) {
        printf("Pilha cheia.\n");
        exit(1);
    }
    pilha->v[pilha->topo++] = valor;
}

char remover(Pilha * pilha) {
    if(pilha->topo == 0) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    pilha->topo--;
    return pilha->v[pilha->topo];
}

int size(Pilha * pilha) {
    return pilha->topo;
}

int estaVazia(Pilha * pilha) {
    return pilha->topo == 0;
}

void printPilha(Pilha * pilha) {
    printf("(");
    for(int i = pilha->topo - 1; i >= 0; i--) {
        printf("%c", pilha->v[i]);
        if(i > 0) {
            printf("<-");
        }
    }
    printf(")(%d)\n", size(pilha));
}

int main() {
    Pilha * pilha = newPilha(10);
    char palavra[10];
    printf("Digite uma palavra: ");
    scanf("%s", &palavra);
    int tamanho = strlen(palavra);
    for(int i = 0; i < tamanho; i++) {
        adicionar(pilha, palavra[i]);
    }

    printf("Palavra revertida: ");
    for(int i = 0; i < tamanho; i++) {
        printf("%c", remover(pilha));
    }
}