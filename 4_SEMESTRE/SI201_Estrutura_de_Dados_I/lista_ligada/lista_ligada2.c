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
    Lista * lista = (Lista *)malloc(sizeof(lista));
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
    No * aux = lista->inicio;
    printf("[");
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
        aux = aux->proximo;
    }
    if(aux == NULL) {
        printf("Fora dos limites.\n");
        exit(1);
    }
    return aux;
}

int remover(Lista * lista, int idx) {
    No * no;
    if(idx < 0 || idx > size(lista)) {
        printf("Fora dos limites.\n");
        exit(1);
    }
    if(idx == 0) {
        no = lista->inicio;
        lista->inicio = lista->inicio->proximo;
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
    No * no = get(lista, idx);
    no->valor = valor;
}

void adicionar(Lista * lista, int valor, int idx) {
    No * no = newNo(valor);
    if(idx == 0) {
        no->proximo = lista->inicio;
        lista->inicio = no;
    } else {
        No * anterior = get(lista, idx);
        no->proximo = anterior->proximo;
        anterior->proximo = no;
    }
}

void inverterLista(Lista * lista) {
    No * anterior = NULL;
    No * atual = lista->inicio;
    No * proximo = NULL;

    while(atual != NULL) {
        proximo = atual->proximo; // Salva o proximo no
        atual->proximo = anterior; // Inverte o ponteiro para o proximo no
        anterior = atual; // Atualiza o no anterior
        atual = proximo;
    }
    lista->inicio = anterior;
}

void concatenarListas(Lista * lista1, Lista * lista2) {
    
}

int main() {
    Lista * lista = newLista();
    adicionarFim(lista, 1);printLista(lista);
    adicionarFim(lista, 2);printLista(lista);
    adicionarFim(lista, 3);printLista(lista);
    adicionarFim(lista, 4);printLista(lista);
    adicionarFim(lista, 5);printLista(lista);
    remover(lista, 0);printLista(lista);
    set(lista, 6, 0);printLista(lista);
    adicionar(lista, 1, 0);printLista(lista);
    adicionar(lista, 10, 1);printLista(lista);
    inverterLista(lista);printLista(lista);
}