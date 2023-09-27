#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No * proximo;
} No;

typedef struct Lista {
    No * inicio;
} Lista;

No * newNo(int valor) {
    No * no = (No *)malloc(sizeof(No));
    no->valor = valor;
    no->proximo = NULL;
    return no;
}

Lista * newLista() {
    Lista * lista = (Lista *)malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}

int estaVazia(Lista * lista) {
    return lista->inicio == NULL;
}

int size(Lista * lista) {
    No * aux = lista->inicio;
    int size = 0;
    while(aux != NULL) {
        aux = aux->proximo;
        size++;
    }
    return size;
}

void adicionarFim(Lista * lista, int valor) {
    No * no = newNo(valor);
    if(estaVazia(lista)) {
        lista->inicio = no;
    } else {
        No * aux = lista->inicio;
        while(aux->proximo != NULL) {
            aux = aux->proximo;
        }
        aux->proximo = no;
    }
}

void printLista(Lista * lista) {
    printf("[");
    No * aux = lista->inicio;
    while(aux != NULL) {
        printf("%d", aux->valor);
        aux = aux->proximo;
        if(aux != NULL) {
            printf(",");
        }
    }
    printf("](%d)\n",size(lista));
}

No * get(Lista * lista, int idx) {
    No * aux = lista->inicio;
    for(int i = 0; i < idx; i++) {
        if(aux != NULL) {
            aux = aux->proximo;
        }
    }
    if(aux == NULL) {
        printf("Indice fora dos parametros.\n");
        exit(1);
    }
    return aux;
}

int remover(Lista * lista, int idx) {
    No * no;
    if(idx == 0) {
        no = lista->inicio;
    } else {
        No * anterior = get(lista, idx-1);
        no = anterior->proximo;
        anterior->proximo = anterior->proximo->proximo;
    }
    int valor = no->valor;
    free(no);
    return valor;
}

void set(Lista * lista, int valor, int idx) {
    No * aux = get(lista, idx);
    aux->valor = valor;
}

void adicionar(Lista * lista, int valor, int idx) {
    No * no = newNo(valor);
    if(idx == 0) {
        no->proximo = lista->inicio;
        lista->inicio = no;
    } else {
        No * anterior = get(lista, idx-1);
        no->proximo = anterior->proximo;
        anterior->proximo = no;
    }
}

void adicionarOrdenado(Lista * lista, int valor) {
    No * no = newNo(valor);
    if(lista->inicio == NULL || valor <= lista->inicio->valor) {
        no->proximo = lista->inicio;
        lista->inicio = no;
    } else {
        No * aux = lista->inicio;
        while(aux->proximo != NULL && aux->proximo->valor < valor) {
            aux = aux->proximo;
        }
        no->proximo = aux->proximo;
        aux->proximo = no;
    }
}

int main() {
    // Criar uma nova lista
    Lista *lista = newLista();

    // Adicionar elementos ao final da lista
    adicionarFim(lista, 10);
    adicionarFim(lista, 20);
    adicionarFim(lista, 30);
    printf("Lista após adicionar elementos no fim: ");
    printLista(lista);

    // Adicionar um elemento em uma posição específica
    adicionar(lista, 15, 1);  // Adicionar o valor 15 na posição 1
    printf("Lista após adicionar 15 na posição 1: ");
    printLista(lista);

    // Atualizar um elemento na lista
    set(lista, 25, 2);  // Atualizar o valor da posição 2 para 25
    printf("Lista após atualizar 25 na posição 2: ");
    printLista(lista);

    // Remover um elemento da lista
    remover(lista, 3);  // Remover o elemento na posição 3
    printf("Lista após remover o elemento na posição 3: ");
    printLista(lista);

    // Verificar se a lista está vazia
    if (estaVazia(lista))
        printf("A lista está vazia.\n");
    else
        printf("A lista não está vazia.\n");

    // Exibir o tamanho da lista
    printf("Tamanho da lista: %d\n", size(lista));

    // Liberar a memória alocada para a lista
    // (na prática, você deve fazer isso no final do seu programa)
    No *current = lista->inicio;
    No *next;
    while (current != NULL) {
        next = current->proximo;
        free(current);
        current = next;
    }
    free(lista);

    return 0;
}