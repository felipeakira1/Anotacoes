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
    return fim - inicio;
}

void printFila() {
    printf("[");
    for(int i = 0; i < MAX; i++) {
        printf("%d", v[i]);
        if(i < MAX - 1) {
            printf(",");
        }
    }
    printf("](%d)",size());
}

int main() {
    adicionar(100);
    adicionar(200);
    adicionar(300);
    adicionar(400);
    adicionar(500);
    printFila();
}