#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore {
    int valor;
    struct NoArvore * esq;
    struct NoArvore * dir;
} NoArvore;

typedef struct Arvore {
    NoArvore * raiz;
} Arvore;

NoArvore * newNoArvore(int valor) {
    NoArvore * aux = (NoArvore *)malloc(sizeof(NoArvore));
    aux->valor = valor;
    aux->esq = NULL;
    aux->dir = NULL;
}

Arvore * newArvore() {
    Arvore * aux = (Arvore *)malloc(sizeof(Arvore));
    aux->raiz = NULL;
}
void addNoRecursivo(NoArvore * no, int valor) {
    if(valor < no->valor) {
        if(no->esq == NULL) {
            no->esq = newNoArvore(valor);
        } else {
            addNoRecursivo(no->esq, valor);
        }
    } else {
        if(no->dir == NULL) {
            no->dir = newNoArvore(valor);
        } else {
            addNoRecursivo(no->dir, valor);
        }
    }
}

void addArvoreRecursivo(Arvore * arvore, int valor) {
    if(arvore->raiz == NULL) {
        arvore->raiz = newNoArvore(valor);
    }
    else {
        addNoRecursivo(arvore->raiz, valor);
    }
}

void addArvoreIterativo(Arvore * arvore, int valor) {
    NoArvore * no = newNoArvore(valor);
    if(arvore->raiz == NULL) {
        arvore->raiz = no;
        return;
    }
    NoArvore * aux = arvore->raiz;
    int inseriu = 0;
    while(!inseriu) {
        if(valor < aux->valor) {
            if(aux->esq == NULL) {
                aux->esq = no;
                inseriu = 1;
            } else {
                aux = aux->esq;
            }
        } else {
            if(aux->dir == NULL) {
                aux->dir = no;
                inseriu = 1;
            } else {
                aux = aux->dir;
            }
        }
    }
}

int alturaArvore(NoArvore * no) {
    if(no == NULL) {
        return 0;
    }
    int alturaEsquerda = alturaArvore(no->esq);
    int alturaDireita = alturaArvore(no->dir);
    if(alturaEsquerda > alturaDireita) {
        return 1 + alturaEsquerda;
    } else {
        return 1 + alturaDireita;
    }
}

int sizeTreeRecursivo(NoArvore * no) {
    if(no == NULL) {
        return 0;
    }
    int sizeEsquerda = sizeTreeRecursivo(no->esq);
    int sizeDireita = sizeTreeRecursivo(no->dir);
    return 1 + sizeEsquerda + sizeDireita;
}

void emOrdem(NoArvore * no) {
    if(no != NULL) {
        emOrdem(no->esq);
        printf("%d ", no->valor);
        emOrdem(no->dir);
    }
}

void preOrdem(NoArvore * no) {
    if(no != NULL) {
        printf("%d ", no->valor);
        preOrdem(no->esq);
        preOrdem(no->dir);
    }
}

void posOrdem(NoArvore * no) {
    if(no != NULL) {
        posOrdem(no->esq);
        posOrdem(no->dir);
        printf("%d ", no->valor);
    }
}

typedef struct NoLista {
    int valor;
    struct NoLista * proximo;
} NoLista;

typedef struct Lista {
    NoLista * inicio;
} Lista;

NoLista * newNoLista(int valor) {
    NoLista * aux = (NoLista *)malloc(sizeof(NoLista));
    aux->valor = valor;
    aux->proximo = NULL;
    return aux;
}

Lista * newLista() {
    Lista * aux = (Lista *)malloc(sizeof(Lista));
    aux->inicio = NULL;
}

void addLista(Lista * lista, int valor) {
    NoLista * no = newNoLista(valor);
    if(lista->inicio == NULL) {
        lista->inicio = no;
    } else {
        NoLista * aux = lista->inicio;
        while(aux->proximo != NULL) {
            aux = aux->proximo;
        }
        aux->proximo = no;
    }
}

int sizeLista(Lista * lista) {
    int size = 0;
    NoLista * aux = lista->inicio;
    while(aux->proximo != NULL) {
        aux = aux->proximo;
        size++;
    }
    return size;
}

void TreeToList(NoArvore * no, Lista * lista) {
    if(no != NULL) {
        TreeToList(no->esq, lista);
        addLista(lista, no->valor);
        TreeToList(no->dir, lista);
    }
}

void TreeSort(Lista * lista) {
    Arvore * arvore = newArvore();
    NoLista * aux = lista->inicio;
    while(aux->proximo != NULL) {
        addArvoreRecursivo(arvore, aux->valor);
        aux = aux->proximo;
    }
    TreeToList(arvore->raiz, lista);
}

void printLista(Lista * lista) {
    NoLista * aux = lista->inicio;
    printf("[");
    while(aux->proximo != NULL) {
        printf("%d", aux->valor);
        aux = aux->proximo;
        if(aux->proximo != NULL) {
            printf(", ");
        }
    }
    printf("](%d)\n",sizeLista(lista));
}

int main() {
    Arvore * arvore = newArvore();
    addArvoreRecursivo(arvore, 5);
    addArvoreRecursivo(arvore, 3);
    addArvoreRecursivo(arvore, 4);
    addArvoreRecursivo(arvore, 2);
    addArvoreRecursivo(arvore, 7);
    addArvoreRecursivo(arvore, 6);
    emOrdem(arvore->raiz);
    printf("\n");
    preOrdem(arvore->raiz);
    printf("\n");
    posOrdem(arvore->raiz);
    printf("\n");

    printf("Altura da arvore: %d\n", alturaArvore(arvore->raiz));
    printf("Tamanho da arvore: %d\n", sizeTreeRecursivo(arvore->raiz));

    Lista * lista = newLista();
    addLista(lista, 1);
    addLista(lista, 3);
    addLista(lista, 5);
    addLista(lista, 4);
    addLista(lista, 2);
    printLista(lista);
    TreeSort(lista);
    printLista(lista);
}