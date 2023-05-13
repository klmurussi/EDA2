/*
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;


void em_ordem (no *raiz) {
    if (raiz == NULL) return;

    em_ordem (raiz->esq);
    printf ("%d ", raiz->dado);
    em_ordem (raiz->dir);
}

no* insere (no *raiz, int x) {
    if (raiz == NULL) {
        no *novo = malloc (sizeof (no));
        novo->dado = x;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }

    if (x < raiz->dado) insere (raiz->esq, x);
    else insere (raiz->dir, x);

    return raiz;
}

int main () {
    no *raiz = NULL;
    int n, i, x;

    scanf ("%d", &n);

    for (i = 0; i < n; i++) {
        scanf ("%d", &x);
        raiz = insere (raiz, x);
    }

    em_ordem (raiz);
    printf ("\n");

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

typedef struct pilha {
    no *dado;
    struct pilha *prox;
} pilha;

no *criar_no (int x, no *pai) {
    no *novo = malloc (sizeof (no));
    novo->dado = x;
    novo->esq = NULL;
    novo->dir = NULL;
    if (pai != NULL) {
        if (x < pai->dado) pai->esq = novo;
        else pai->dir = novo;
    }
    return novo;
}

pilha *push (pilha *p, no *x) {
    pilha *novo = malloc (sizeof (pilha));
    novo->dado = x;
    novo->prox = p;
    return novo;
}

no *pop (pilha **p) {
    if (*p == NULL) return NULL;
    pilha *aux = *p;
    *p = (*p)->prox;
    no *x = aux->dado;
    free (aux);
    return x;
}

void em_ordem (no *raiz) {
    if (raiz == NULL) return;

    no *aux = raiz;
    pilha *p = NULL;

    while (aux != NULL || p != NULL) {
        if (aux != NULL) {
            p = push (p, aux);
            aux = aux->esq;
        }
        else {
            aux = pop (&p);
            printf ("%d ", aux->dado);
            aux = aux->dir;
        }
    }   
}

int main() {
    /* Exemplo de árvore binária de busca:
                 3
               /   \
              2     5
             /     / \
            1     4   8
                     / \
                    7   9
                   /
                  6 
    */

    no *raiz = criar_no(3, NULL);
    no *no2 = criar_no(5, raiz);
    no *no3 = criar_no(4, no2);
    no *no4 = criar_no(8, no2);
    no *no5 = criar_no(2, raiz);
    no *no6 = criar_no(1, no5);
    no *no7 = criar_no(9, no4);
    no *no8 = criar_no(7, no7);
    no *no9 = criar_no(6, no8);    

    em_ordem (raiz);

    free (no9);
    free (no8);
    free (no7);
    free (no6);
    free (no5);
    free (no4);
    free (no3);
    free (no2);
    free (raiz);

    return 0;

}
   