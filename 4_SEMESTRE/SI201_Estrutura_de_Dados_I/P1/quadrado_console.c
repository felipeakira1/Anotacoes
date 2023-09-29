#include <stdio.h>

void desenharQuadrado(int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        for(int j = 0; j < tamanho; j++) {
            if(i == 0 || i == tamanho - 1 || j == 0 || j == tamanho - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}
int main() {
    int tamanho = 0;
    while (1) {
        printf("Digite o tamanho do lado do quadrado: (negativo para sair): ");
        scanf("%d", &tamanho);
        if(tamanho < 0) {
            break;
        }
        desenharQuadrado(tamanho);
    }
    return 0;
}