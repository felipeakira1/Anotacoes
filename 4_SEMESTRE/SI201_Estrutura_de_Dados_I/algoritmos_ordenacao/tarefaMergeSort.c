#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void selecao_iterativo(int v[], int n) {
    for(int tamanho = n; tamanho > 1; tamanho--) {
        int maximo = 0;
        for (int i = 0; i < tamanho; i++) {
            if(v[i] > v[maximo]) {
                maximo = i;
            }
        }
        int aux = v[tamanho-1];
        v[tamanho-1] = v[maximo];
        v[maximo] = aux;
    }
}

void merge(int v1[], int n1, int v2[], int n2, int v[]) {
    int top1 = 0, top2 = 0, top = 0;
    while(top1 < n1 && top2 < n2) {
        if(v1[top1] < v2[top2]) {
            v[top++] = v1[top1++];
        } else {
            v[top++] = v2[top2++];
        }
    }
    while(top1 < n1)  {
        v[top++] = v1[top1++];
    }
    while(top2 < n2) {
        v[top++] = v2[top2++];
    }
}

void merge_sort(int v[], int n) {
    if(n > 1) {
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

void popularVetor(int v[], int n) {
    for(int i = 0; i < n; i++) {
        v[i] = rand()%n;
    }
}
int main() {
    int n = 1000000;

    int * v;
    v = (int *)malloc(sizeof(int) * n);
    popularVetor(v, n);

    time_t start, end;
    print(v, n);
    time(&start);
    merge_sort(v, n);
    time(&end);
    double dif = difftime(end, start);
    printf("%lf segundos \n", dif);

    print(v, n);
}