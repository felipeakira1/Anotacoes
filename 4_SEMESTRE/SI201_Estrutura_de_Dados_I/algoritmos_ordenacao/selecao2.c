#include <stdio.h>
#include <stdlib.h>

void print(int v[], int n) {
    printf("[");
    for(int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if(i < n - 1) {
            printf(", ");
        }
    }
        printf("]\n");
}

void selecao_iterativo(int v[], int n) {
    for(int tamanho = n; tamanho > 1; tamanho--) {
        int maximo = 0;
        for(int i = 0; i < tamanho; i++) {
            if(v[i] > v[maximo]) {
                maximo = i;
            }
        }
        int aux = v[tamanho-1];
        v[tamanho-1] = v[maximo];
        v[maximo] = aux;
    }
}

void selecao_recursivo(int v[], int n) {
    if(n > 1) {
        int maximo = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] > v[maximo]) {
                maximo = i;
            }
        }
        int aux = v[n-1];
        v[n-1] = v[maximo];
        v[maximo] = aux;
        n--;
        selecao_recursivo(v, n);
    }
}

void bubble_sort_iterativo(int v[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(v[j] > v[j+1]) {
                int aux = v[j+1];
                v[j+1] = v[j];
                v[j] = v[j+1];
            }
        }
    }
}

void merge(int * v1, int n1, int * v2, int n2, int * v) {
    int top1 = 0, top2 = 0, top = 0;
    while(top1 < n1 && top2 < n2) {
        if(v1[top1] < v2[top2]) {
            v[top++] = v1[top1++];
        } else {
            v[top++] = v2[top2++];
        }
    }

    while(top1 < n1) {
        v[top++] = v1[top1++];
    }
    while(top2 < n2) {
        v[top++] = v2[top2++];
    }
}

void merge_sort(int v[], int n) {
    if (n > 1) {
        int n1, n2;
        n1 = n/2;
        n2 = n - n1;
        int * v1, * v2;
        v1 = (int *)malloc(sizeof(int) * n1);
        v2 = (int *)malloc(sizeof(int) * n2);

        for(int i = 0; i < n1; i++) {
            v1[i] = v[i];
        }

        for(int i = 0; i < n2; i++) {
            v2[i] = v[n1 + i];
        }

        merge_sort(v1, n1);
        merge_sort(v2, n2);
        merge(v1, n1, v2, n2, v);
        free(v1);
        free(v2);
    }
}

int busca_binaria(int v[], int n, int chave) {
    int inicio = 0;
    int fim = n - 1;

    while(inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if(v[meio] == chave) {
            return meio;
        }
        if(chave < v[meio]) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return -1;
}

int particao(int v[], int inicio, int fim) {
    int pivo = v[inicio];
    int topo = inicio;

    for(int i = inicio + 1; i <= fim; i++) {
        if(v[i] < pivo) {
            topo++;
            int temp = v[topo];
            v[topo] = v[i];
            v[i] = temp;
        }
    }
    v[inicio] = v[topo];
    v[topo] = pivo;
    return topo;
}

void quick_sort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int indice_pivo = particao(v, inicio, fim);
        quick_sort(v, inicio, indice_pivo-1);
        quick_sort(v, indice_pivo+1, fim);
    }
}



int main() {
    // int n = 100000;
    // int * v;
    // v = (int *)malloc(sizeof(int) * n);

    // for (int i = 0; i < n; i++) {
    //     v[i] = rand() % 100;
    // }
    // int v[] = {9, 10, 3, 2, 0, 8, 7, 5, 1, 4};
    // int n = 10;

    // print(v, n);
    // quick_sort(v,n);
    // print(v, n);
    // printf("O indice do elemento 10 eh: %d\n", busca_binaria(v, n, 10));
    // print(v, n);
    printf("%d", 5/2);
}