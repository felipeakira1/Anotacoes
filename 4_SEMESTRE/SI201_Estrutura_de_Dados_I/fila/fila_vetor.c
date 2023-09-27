#include <stdio.h>
#define MAX 10

int v[MAX];
int inicio = 0;
int fim = 0;

void adicionar(int valor) {
    v[fim++] = valor;
}

int remover() {
    int valor = v[inicio];
    v[inicio] = 0;
    inicio++;
    return valor;
}

int estaVazia() {
    return inicio == fim;
}

int size() {
    return fim-inicio;
}

void printFila() {
    printf("[");
    for(int i = 0; i < fim; i++) {
        printf("%d", v[i]);
        if(i < fim-1) {
            printf(",");
        }
    }
    printf("](%d)\n", size());
}
int main() {
    adicionar(1);
    adicionar(2);
    adicionar(3);
    adicionar(4);
    adicionar(5);
    printFila();
    remover();
    printFila();
    remover();
    printFila();
    remover();
    printFila();
    remover();
}