// Integrantes do Grupo:
// Felipe Akira Nozaki - RA 172885
// Henrique Bexiga Eulalio - RA 255002
// Vinicius Vasconcelos - RA 174265

#include <stdio.h>
#include <stdlib.h>

#define PRIORIDADE_MAXIMA 100

typedef struct No {
    int valor;
    struct No * proximo;
} No;

No * newNo(int valor) {
    No * aux = (No *)malloc(sizeof(No));
    aux->valor = valor;
    aux->proximo = NULL;
    return aux;
}

typedef struct Fila {
    No * inicio;
    No * fim;
} Fila;

Fila * newFila() {
    Fila * aux = (Fila *)malloc(sizeof(Fila));
    aux->inicio = NULL;
    aux->fim = NULL;
    return aux;
}

typedef struct FilaPrioridades {
    Fila * filas[PRIORIDADE_MAXIMA];
} FilaPrioridades;

FilaPrioridades * newFilaPrioridades(int max) {
    FilaPrioridades * aux = (FilaPrioridades *)malloc(sizeof(FilaPrioridades));
    for(int i = 0; i < max; i++) {
        aux->filas[i] = newFila();
    }
    return aux;
}

void adicionar(FilaPrioridades * fp, int valor, int prioridade) {
    if(prioridade < 0 || prioridade > PRIORIDADE_MAXIMA) {
        printf("Prioridade invalida.\n");
        return;
    }

    No * no = newNo(valor);
    
    Fila * fila = fp->filas[prioridade];
    if(fila->inicio == NULL) {
        fila->inicio = no;
        fila->fim = no;
    } else {
        fila->fim->proximo = no;
        fila->fim = no;
    }
}

int filaEstaVazia(Fila * fila) {
    return fila->inicio == NULL;
}

int filaPrioridadesVazia(FilaPrioridades * fp) {
    Fila * aux = fp->filas[0];
    return filaEstaVazia(aux);
}

void remover(FilaPrioridades * fp, int max) {
    if(filaPrioridadesVazia(fp)) {
        printf("A fila de prioridades esta vazia.\n");
        return;
    }
    for(int i = 0; i < max; i++) {
        Fila * fila = fp->filas[i];
        if(fila->inicio != NULL) {
            No * aux = fila->inicio;
            int valor = aux->valor;
            fila->inicio = fila->inicio->proximo;
            free(aux);
            printf("Elemento removido: %d (prioridade: %d)\n", valor, i);
            return;
        }
    }
}

void printFilaPrioridades(FilaPrioridades * fp, int max) {
    for(int i = 0; i < max; i++) {
        printf("Prioridade: %d: [", i);
        No * aux = fp->filas[i]->inicio;
        while(aux != NULL) {
            printf("%d", aux-> valor);
            if(aux->proximo != NULL) {
                printf(", ");
            }
            aux = aux->proximo;
        }
        printf("]\n");
    }
}


int main() {
    int prioridades;
    printf("Digite o valor maximo para a prioridade: ");
    scanf("%d", &prioridades);
    if(prioridades < 0 || prioridades >= PRIORIDADE_MAXIMA) {
        printf("Valor maximo de prioridade invalido.\n");
        return 1;
    }

    FilaPrioridades * fp = newFilaPrioridades(prioridades);

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover um elemento\n");
        printf("3. Imprimir a fila de prioridades\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int valor, prioridade;
                printf("Digite o valor do elemento: ");
                scanf("%d", &valor);
                printf("Digite a prioridade do elemento (entre 0 e %d): ", prioridades - 1);
                scanf("%d", &prioridade);
                adicionar(fp, valor, prioridade);
                break;
            }
            case 2:
                remover(fp, prioridades);
                break;
            case 3:
                printFilaPrioridades(fp, prioridades);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);
}