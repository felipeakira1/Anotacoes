#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No * proximo;
} No;

typedef struct Fila {
    No * inicio;
    No * fim;
} Fila;

typedef struct FilaPrioridades {
    Fila * prioritario;
    Fila * normal;
} FilaPrioridades;

No * newNo(int valor) {
    No * no = (No *)malloc(sizeof(No));
    no->valor = valor;
    no->proximo = NULL;
    return no;
}

Fila * newFila() {
    Fila * fila = (Fila *)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

int filaEstaVazia(Fila * fila) {
    return fila->inicio == NULL;
}

int size(Fila * fila) {
    int size = 0;
    No * aux = fila->inicio;
    while(aux != NULL) {
        size++;
        aux = aux->proximo;
    }
    return size;
}
void adicionarFila(Fila * fila, int valor) {
    No * no = newNo(valor);
    if(filaEstaVazia(fila)) {
        fila->inicio = no;
        fila->fim = no;
    } else {
        fila->fim->proximo = no;
        fila->fim = no;
    }
}

int removerFila(Fila * fila) {
    if(filaEstaVazia(fila)) {
        printf("Fila vazia.\n");
        exit(1);
    }
    No * no = fila->inicio;
    int valor = no->valor;
    if(fila->inicio == fila->fim) {
        fila->inicio = NULL;
        fila->fim = NULL;
    } else {
        fila->inicio = fila->inicio->proximo;
    }
    free(no);
    return valor;
}

 void printFila(Fila * fila) {
     printf("[");
     No * aux = fila->inicio;
     while(aux != NULL) {
        printf("%d", aux->valor);
        aux = aux->proximo;
        if(aux != NULL) {
            printf(",");
        }
     }
     printf("](%d)\n",size(fila));
 }

FilaPrioridades * newFilaPrioridades() {
    FilaPrioridades * filaPrioridades = (FilaPrioridades *)malloc(sizeof(FilaPrioridades));
    filaPrioridades->prioritario = newFila();
    filaPrioridades->normal = newFila();
    return filaPrioridades;
}

void adicionarFilaPrioridades(FilaPrioridades * filaPrioridades, int valor, int prioridade) {
    if(prioridade) {
        adicionarFila(filaPrioridades->prioritario, valor);
    } else {
        adicionarFila(filaPrioridades->normal, valor);
    }
}

int removerFilaPrioridades(FilaPrioridades * filaPrioridades) {
    if(!filaEstaVazia(filaPrioridades->prioritario)) {
        return removerFila(filaPrioridades->prioritario);
    } else {
        return removerFila(filaPrioridades->normal);
    }
}

void printFilaPrioridades(FilaPrioridades * filaPrioridades) {
    printf("Prioritarios: ");
    printFila(filaPrioridades->prioritario);
    printf("Normal: ");
    printFila(filaPrioridades->normal);
}

int main() {
    FilaPrioridades * fp = newFilaPrioridades();
    adicionarFilaPrioridades(fp, 1, 0);
    adicionarFilaPrioridades(fp, 2, 0);
    adicionarFilaPrioridades(fp, 2, 1);
    adicionarFilaPrioridades(fp, 2, 1);
    printFilaPrioridades(fp);
    removerFilaPrioridades(fp);
    removerFilaPrioridades(fp);
    removerFilaPrioridades(fp);
    removerFilaPrioridades(fp);
    printFilaPrioridades(fp);
}