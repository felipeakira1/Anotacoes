#include <stdio.h>

int maximo(int v[], int n) {
    int max = 0;
    for(int i = 1; i < n; i++) {
        if(v[i] > v[max]) {
            max = i;
        }
    }
    return max;
}

void selecao_duas_funcoes(int v[], int n) {
    while(n > 1) {
        // Seleciona o maior elemento
        int max = maximo(v, n);

        // Coloca na última posição
        int aux = v[n-1]; // Armazena o valor da última posição do vetor
        v[n-1] = v[max]; // Define o valor da última posição do vetor igual ao maior elemento
        v[max] = aux; // Define o valor da antiga posição do maior elemento como o valor da última posição do vetor

        // Repete o processo no vetor desconsiderando o último elemento
        n--;
    }
}

void selecao(int v[], int n) {
    for(int N = n; N > 1; N--) {
        int max = 0;
        for(int i = 1; i < N; i++) {
            if(v[i] > v[max]) {
                max = i;
            }
        }
        int aux = v[N-1];
        v[N-1] = v[max];
        v[max] = aux;
    }
}

void selecao_recursivo(int v[], int n) {
    if(n > 1) {
        print(v, n);
        int max = 0;
        for(int i = 1; i < n; i++) {
            if(v[i] > v[max]) {
                max = i;
            }
        }
        int aux =v[n-1];
        v[n-1] = v[max];
        v[max] = aux;
        print(v,n);
        selecao_recursivo(v, n-1);
    }
}

void bolha_recursiva(int v[], int n) {
    if(n > 1) {
        for(int i = 0; i < n-1; i++) {
            if(v[i] > v[i+1]) {
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            }
        }
        bolha_recursiva(v, n-1);
    }
}

void bolha_iterativa(int v[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(v[i] > v[i+1]) {
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            }
        }
    }
}

void insercaoA(int v[], int n) {
    int lixo = -1;
    int chave = v[n-1];
    v[n-1] = lixo;
    int i = n-2;
    print(v,n);
}