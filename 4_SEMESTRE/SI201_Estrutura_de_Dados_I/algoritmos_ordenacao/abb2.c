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

void addTree(Tree * tree, int valor) {
    No * no = newNo(valor);
    if(tree->raiz == NULL) {
        tree->raiz = no;
        return;
    }
    No * aux = tree->raiz;
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
    if (no != NULL) {
        emOrdem(no->esq);
        printf(" %d", no->valor);
        emOrdem(no->dir);
    }
}

void preOrdem(No * no) {
    if (no != NULL) {
        printf(" %d", no->valor);
        preOrdem(no->esq);
        preOrdem(no->dir);
    }
}

void posOrdem(No * no) {
    if (no != NULL) {
        posOrdem(no->esq);
        posOrdem(no->dir);
        printf(" %d", no->valor);
    }
}

No * busca_recursiva(No * no, int valor) {
    if (no == NULL) {
        return NULL;
    } else {
        if (no->valor == valor) {
            return no;
        } else {
            if(valor < no->valor) {
                busca_recursiva(no->esq, valor);
            } else {
                busca_recursiva(no->dir, valor);
            }
        }
    }
}

int sizeTree(No * no) {
    if(no == NULL) {
        return 0;
    } else {
        int sizeEsq = sizeTree(no->esq);
        int sizeDir = sizeTree(no->dir);
        return 1 + sizeEsq + sizeDir;
    }
}

int altura(No * no) {
    if(no == NULL) {
        return 0;
    } else {
        int alturaEsq = altura(no->esq);
        int alturaDir = altura(no->dir);
        if(alturaEsq > alturaDir) {
            return 1 + alturaEsq;
        } else {
            return 1 + alturaDir;
        }
    }
}

int main() {
    Tree * tree = newTree();
    addTree(tree, 7);
    addTree(tree, 5);
    addTree(tree, 8);
    addTree(tree, 1);
    addTree(tree, 4);
    addTree(tree, 3);
    emOrdem(tree->raiz);
    printf("\n");
    preOrdem(tree->raiz);
    printf("\n");
    posOrdem(tree->raiz);
    printf("\n%d", altura(tree->raiz));
}