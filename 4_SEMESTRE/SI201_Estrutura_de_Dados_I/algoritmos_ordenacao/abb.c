#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No * esq;
    struct No * dir;
} No;

typedef struct Tree {
    No * raiz;
} Tree;

No * newNo(int valor) {
    No * aux = (No *)malloc(sizeof(No));
    aux->valor = valor;
    aux->esq = NULL;
    aux->dir = NULL;
    return aux;
}

Tree * newTree() {
    Tree * aux = (Tree *)malloc(sizeof(Tree));
    aux->raiz = NULL;
    return aux;
}

void addTree(Tree * t, int valor) {
    No * no = newNo(valor);
    if(t->raiz == NULL) {
        t->raiz = no;
        return;
    }
    No * aux = t->raiz;
    int inseriu = 0;
    while(!inseriu) {
        if(valor < aux->valor) {
            if(aux->esq != NULL) {
                aux = aux->esq;
            } else {
                aux->esq = no;
                inseriu = 1;
            }
        } else {
            if(aux->dir != NULL) {
                aux = aux->dir;
            } else {
                aux->dir = no;
                inseriu = 1;
            }
        }
    }
}

void emOrdem(No * no) {
    if(no != NULL) {
        emOrdem(no->esq);
        printf(" %d", no->valor);
        emOrdem(no->dir);
    }
}

void preOrdem(No * no) {
    if(no != NULL) {
        printf(" %d", no->valor);
        preOrdem(no->esq);
        preOrdem(no->dir);
    }
}

void posOrdem(No * no) {
    if(no != NULL) {
        posOrdem(no->esq);
        posOrdem(no->dir);
        printf(" %d", no->valor);
    }
}

/* Lista ligada */
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
    return aux;
}

void addLista(Lista * lista, int valor) {
    NoLista * no = newNoLista(valor);
    if(lista->inicio == NULL) {
        lista->inicio = no;
        return;
    }
    NoLista * aux = lista->inicio;
    while(aux->proximo != NULL) {
        aux = aux->proximo;
    }
    aux->proximo = no;
}

void printLista(Lista * lista) {
    NoLista * aux = lista->inicio;
    printf("\n[");
    while(aux != NULL) {
        printf("%d", aux->valor);
        aux = aux->proximo;
        if(aux != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

int sizeTree(No * no) {
    if(no == NULL) {
        return 0;
    } else {
        int sizeEsq = sizeTree(no->esq);
        int sizeDir = sizeTree(no->dir);
        return sizeEsq + sizeDir + 1;
    }
}

int altura(No * no) {
    if(no == NULL) {
        return 0;
    } else {
        int alturaEsq = altura(no->esq);
        int alturaDir = altura(no->dir);
        if(alturaEsq > alturaDir) {
            return alturaEsq + 1;
        } else {
            return alturaDir + 1;
        }
    }
}

No * busca_recursiva(No * no, int valor) {
    if(no == NULL) {
        return NULL;
    } else {
        if(no->valor == valor) {
            return no;
        } else {
            if(valor < no->valor) {
                return busca_recursiva(no->esq, valor);
            } else {
                return busca_recursiva(no->dir, valor);
            }
        }
    }
}

No * busca_iterativa(No * no, int valor) {
    No * aux = no;
    while(aux != NULL) {
        if(aux->valor == valor) {
            return aux;
        }
        if(valor < aux->valor) {
            aux = aux->esq;
        } else {
            aux = aux->dir;
        }
    }
    return NULL;
}

void treeToList(No * no, Lista * lista) {
    if(no == NULL) {
        return;
    }
    treeToList(no->esq, lista);
    addLista(lista, no->valor);
    treeToList(no->dir, lista);
}

int main() {
    Tree * tree = newTree();
    addTree(tree, 7);
    addTree(tree, 8);
    addTree(tree, 4);
    addTree(tree, 6);
    addTree(tree, 3);
    addTree(tree, 9);
    addTree(tree, 10);
    emOrdem(tree->raiz);
    printf("\nTamanho da arvore: %d", sizeTree(tree->raiz));
    printf("\nAltura da arvore: %d", altura(tree->raiz));
    Lista * lista = newLista();
    treeToList(tree->raiz, lista);
    printLista(lista);
}