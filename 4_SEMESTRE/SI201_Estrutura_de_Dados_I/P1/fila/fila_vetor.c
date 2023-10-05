#include <stdio.h>
#define MAX 10

int v[MAX];
int inicio = 0, fim = 0;

void adicionar(int valor) {
    v[fim++] = valor;
}

int remover() {
    int valor = v[inicio];
    v[inicio] = 0;
    inicio++;
    return valor;
}

int main() {
    
}