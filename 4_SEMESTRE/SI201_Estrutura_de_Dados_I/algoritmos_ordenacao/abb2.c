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
    return aux;
}

Arvore * newArvore() {
    Arvore * aux = (Arvore *)malloc(sizeof(Arvore));
    aux->raiz = NULL;
    return aux;
}

void addNo(NoArvore * no, int valor) {
    if(valor < no->valor) {
        if(no->esq == NULL) {
            no->esq = newNoArvore(valor);
        } else {
            addNo(no->esq, valor);
        }
    } else {
        if(no->dir == NULL) {
            no->dir = newNoArvore(valor);
        } else {
            addNo(no->dir, valor);
        }
    }
}

void addArvoreRecursivo(Arvore * arvore, int valor) {
    if(arvore->raiz == NULL) {
        arvore->raiz = newNoArvore(valor);
    } else {
        addNo(arvore->raiz, valor);
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

int alturaRecursivo(NoArvore * no) {
    if(no == NULL) {
        return 0;
    }
    int alturaEsquerda = alturaRecursivo(no->esq);
    int alturaDireita = alturaRecursivo(no->dir);

    if(alturaEsquerda > alturaDireita) {
        return 1 + alturaEsquerda;
    } else {
        return 1 + alturaDireita;
    }
}

void emOrdem(NoArvore * no) {
    if(no != NULL) {
        emOrdem(no->esq);
        printf(" %d", no->valor);
        emOrdem(no->dir);
    }
}

void printArvore(Arvore * arvore) {
    printf("[");
    emOrdem(arvore->raiz);
    printf("]\n");
}

NoArvore * buscaArvoreRecursivo(NoArvore * no, int valor) {
    if(valor == no->valor) {
        return no;
    }
    if(valor < no->valor) {
        buscaArvoreRecursivo(no->esq, valor);
    } else {
        buscaArvoreRecursivo(no->dir, valor);
    }
    return NULL;
}

NoArvore * buscaArvoreIterativo(NoArvore * no, int valor) {
    NoArvore * aux = no;
    while(aux != NULL) {
        if(valor == no->valor) {
            return no;
        }
        if(valor < aux->valor) {
            aux = aux->esq;
        } else {
            aux = aux->dir;
        }
    }
    return NULL;
}

int sizeArvoreRecursivo(NoArvore * no) {
    if(no == NULL) {
        return 0;
    }
    int sizeEsquerdo = sizeArvoreRecursivo(no->esq);
    int sizeDireito = sizeArvoreRecursivo(no->dir);
    return 1 + sizeEsquerdo + sizeDireito;
}

typedef struct Lista {
    int * v;
    int top, max;
} Lista;

Lista * newLista(int max) {
    Lista * lista = (Lista *)malloc(sizeof(Lista));
    lista->v = (int *)malloc(sizeof(int) * max);
    lista->top = 0;
    lista->max = max;
    return lista;
}

void addLista(Lista * lista, int valor) {
    if(lista->top == lista->max) {
        printf("Lista esta cheia!\n");
    }
    lista->v[lista->top++] = valor;
}

void ArvoreParaLista(NoArvore * no, Lista * lista) {
    if(no != NULL) {
        ArvoreParaLista(no->esq, lista);
        addLista(lista, no->valor);
        ArvoreParaLista(no->dir, lista);
    }
}

void TreeSort(Lista * lista) {
    if(lista->top <= 1) {
        return;
    }
    Arvore * arvore = newArvore();
    for(int i = 0; i < lista->top; i++) {
        addArvoreRecursivo(arvore, lista->v[i]);
    }
    lista->top = 0;
    ArvoreParaLista(arvore->raiz, lista);
}

void printLista(Lista * lista) {
    printf("[");
    for(int i = 0; i < lista->top; i++) {
        printf("%d", lista->v[i]);
        if(i < lista->top - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void buscarNosComValorArvore(NoArvore * no, int valor, Lista * lista) {
    if(no == NULL) {
        return;
    }
    if(valor == no->valor) {
        addLista(lista, valor);
    }
    buscarNosComValorArvore(no->esq, valor, lista);
    buscarNosComValorArvore(no->dir, valor, lista);
}

Lista * buscarValoresArvore(Arvore * arvore, int valor) {
    Lista * lista = newLista(10);
    buscarNosComValorArvore(arvore->raiz, valor, lista);
    return lista;
}

int main() {
    Arvore * arvore = newArvore();
    addArvoreIterativo(arvore, 7);
    addArvoreIterativo(arvore, 4);
    addArvoreIterativo(arvore, 3);
    addArvoreIterativo(arvore, 3);
    addArvoreIterativo(arvore, 1);
    printArvore(arvore);
    printf("Altura da arvore: %d\n", alturaRecursivo(arvore->raiz));
    printf("Tamanho da arvore: %d\n", sizeArvoreRecursivo(arvore->raiz));
    
    Lista * lista = newLista(10);
    addLista(lista, 7);
    addLista(lista, 5);
    addLista(lista, 9);
    addLista(lista, 3);
    addLista(lista, 2);
    printLista(lista);
    TreeSort(lista);
    printLista(lista);

    Lista * lista2 = buscarValoresArvore(arvore, 3);
    printLista(lista2);
    
}