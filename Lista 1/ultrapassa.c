#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} typedef node;

void insert (node **array, int n) {
    node *new = malloc(sizeof(node));
    new->data = n;
    new->next = NULL;
    if (*array == NULL) {
        *array = new;
    } else {
        node *aux = *array;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = new;
    }
}

void search (node *array, int limit) {
    if (array == NULL) return;

    int soma = 0;
    while (array != NULL) {
        soma += array->data;
        if (soma > limit) {
            search (array->next, limit);
            printf ("%d\n", array->data);
            break;
        }
        array = array->next;
    }
}

int main () {
    node *array = NULL;
    int n, limit, soma = 0;
    while (1) {
        scanf ("%d", &n);
        if (n == 0) {
            break;
        }
        insert(&array, n);
    }
    scanf ("%d", &limit);
    search(array, limit);

    return 0;
}