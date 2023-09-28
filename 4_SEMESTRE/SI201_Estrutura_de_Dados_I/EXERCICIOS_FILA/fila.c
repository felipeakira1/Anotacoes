#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

int contador = 0;
typedef struct Usuario {
    char nome[MAX];
    int senha;
} Usuario;

typedef struct No {
    Usuario * usuario;
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

Usuario * newUsuario(char * nome) {
    Usuario * usuario = (Usuario *)malloc(sizeof(Usuario));
    strcpy(usuario->nome, nome);
    usuario->senha = ++contador;
    return usuario;
}

No * newNo(Usuario * usuario) {
    No * no = (No *)malloc(sizeof(No));
    no->usuario = usuario;
    no->proximo = NULL;
    return no;
}

Fila * newFila() {
    Fila * fila = (Fila *)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

FilaPrioridades * newFilaPrioridades() {
    FilaPrioridades * fp = (FilaPrioridades *)malloc(sizeof(FilaPrioridades));
    fp->normal = newFila();
    fp->prioritario = newFila();
    return fp;
}

void adicionarFila(Fila * fila, char * nome) {
    Usuario * usuario = newUsuario(nome);
    No * no = newNo(usuario);
    if(fila->inicio == NULL) {
        fila->inicio = no;
        fila->fim = no;
    } else {
        fila->fim->proximo = no;
        fila->fim = no;
    }
}

void adicionarFilaPrioridade(FilaPrioridades * fp, char * nome, int prioridade) {
    if(prioridade) {
        adicionarFila(fp->prioritario, nome);
    } else {
        adicionarFila(fp->normal, nome);
    }
    printf("\nUsuario %s adicionado com sucesso na fila de prioridade %d ", nome, prioridade);
    if(prioridade) {
        printf("prioritario.");
    } else {
        printf("normal.");  
    }
}

int estaVazia(Fila * fila) {
    return fila->inicio == NULL;
}

Usuario * removerFila(Fila * fila) {
    if(estaVazia(fila)) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    No * aux = fila->inicio;
    Usuario * usuario = aux->usuario;
    if(fila->inicio == fila->fim) {
        fila->inicio = NULL;
        fila->fim = NULL;
    } else {
        fila->inicio = fila->inicio->proximo;
    }
    free(aux);
    return usuario;
}

Usuario * removerFilaPrioridades(FilaPrioridades * fp) {
    if(!estaVazia(fp->prioritario)) {
        return removerFila(fp->prioritario);
    } else {
        return removerFila(fp->normal);
    }
}

int size(Fila * fila) {
    No * aux = fila->inicio;
    int size = 0;
    while(aux != NULL) {
        aux = aux->proximo;
        size++;
    }
    return size;
}

void printFila(Fila * fila) {
    No * aux = fila->inicio;
    printf("[");
    while(aux != NULL) {
        printf("(%s - %d)", aux->usuario->nome, aux->usuario->senha);
        aux = aux->proximo;
        if(aux != NULL) {
            printf(",");
        }
    }
    printf("](%d)\n",size(fila));
}

void printFilaPrioridades(FilaPrioridades * fp) {
    printf("Fila prioritaria: ");
    printFila(fp->prioritario);
    printf("Fila normal: ");
    printFila(fp->normal);
}

void criarUsuario(FilaPrioridades * fp) {
    for(int i = 0; i < 20; i++)
        printf("=");
    printf("\n");
    
    char nome[MAX];
    int prioridade;

    printf("Digite o nome do usuario: ");
    scanf("%s", &nome);
    fflush(stdin);
    printf("Digite a prioridade (1: prioritario | 0: normal): ");
    scanf("%d", &prioridade);

    adicionarFilaPrioridade(fp, nome, prioridade);
}

void removerUsuario(FilaPrioridades * fp) {
    Usuario * usuarioRemovido = removerFilaPrioridades(fp);
    printf("Usuario removido com sucesso.\n");
    printf("Nome: %s\nSenha: %d\n", usuarioRemovido->nome, usuarioRemovido->senha);
}

int main() {
    FilaPrioridades * fp = newFilaPrioridades();
    int opcao = 0;
    do {
        printf("\n");
        for(int i = 0; i < 20; i++)
            printf("=");
        printf("\n");
        printf("1. Adicionar usuario\n");
        printf("2. Visualizar fila\n");
        printf("3. Remover usuario\n");
        printf("4. Sair\n");
        for(int i = 0; i < 20; i++)
            printf("=");
        printf("\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                criarUsuario(fp);
                break;
            
            case 2:
                printFilaPrioridades(fp);
                break;
            
            case 3:
                removerUsuario(fp);
                break;

            default:
                break;
        }
    } while(opcao != 4);
}