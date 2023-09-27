#include <stdio.h>
#define MAX 5

int v[MAX];
int inicio = 0;
int fim = 0;

void adicionar(int valor) {
    v[fim] = valor;
    fim = (fim+1)%MAX;
}

int remover() {
    int valor = v[inicio];
    v[inicio] = 0;
    inicio = (inicio + 1) % MAX;
    return valor;
}

int size() {
    if(fim > inicio) {
        return fim - inicio;
    } else {
        return fim - inicio + MAX;
    }
}

void printFila() {
    printf("[");
    for(int i = 0; i < MAX; i++) {
        printf("%d", v[i]);
        if(i < MAX-1) {
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
    printFila();
    adicionar(1);
    adicionar(2);
    printFila();
    remover();
    printFila();
}