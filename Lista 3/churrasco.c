#include <stdio.h>
#include <stdlib.h>

struct node {
    int nota;
    int indice;
};

int insert(struct node *heap[], int nota, int indice) {
    heap[indice]->nota = nota;
    heap[indice]->indice = indice;
    int pos = indice;

    for (int i = indice; i > 0; i--) {
        if (heap[i]->nota < heap[i-1]->nota) {
            struct node *aux = heap[i];
            heap[i] = heap[i-1];
            heap[i-1] = aux;
            pos = i-1;
        } else {
            break;
        }
    }

    /*printf ("heap: ");
    for (int i = 0; i <= indice; i++) {
        printf("%d ", heap[i]->nota);
    }
    printf("\n");*/
    return pos;
}

void removeMin(struct node *heap[], int nota, int tam) {
    //printf ("nota: %d\n", nota);
    //printf ("imprime: ");
    printf ("%d", heap[0]->nota);
    int indice;
    for (int i = 0; i <= tam; i++) {
        //printf ("aqui");
        if (heap[i]->nota == nota) {
            indice = i;
            //printf ("indice: %d\n", indice);
            break;
        }
    }
    struct node *aux = heap[indice];
    heap[indice] = heap[tam];
    heap[tam] = aux;
    /*printf ("\nheap: ");
    for (int i = 0; i <= tam; i++) {
        printf("%d ", heap[i]->nota);
    }*/

    //printf ("aqui\n");
    for (int i = indice; i < tam-1; i++) {
        if (heap[i]->nota > heap[i+1]->nota) {
            struct node *aux = heap[i];
            heap[i] = heap[i+1];
            heap[i+1] = aux;
        } else {
            break;
        }
    }

    /*printf ("heap organizada: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", heap[i]->nota);
    }
    printf("\n");*/
}

int main() {
    int qtdAmigos, qtdChurrascarias;
    while (1) {
        scanf("%d %d", &qtdChurrascarias, &qtdAmigos);
        if (qtdAmigos == 0 && qtdChurrascarias == 0) {
            break;
        }
        struct node **heap = malloc((qtdAmigos+1) * sizeof(struct node*));
        for (int i = 0; i < qtdAmigos; i++) {
            heap[i] = malloc(sizeof(struct node));
        }
        struct node *all = malloc(qtdChurrascarias * sizeof(struct node));
        int sizeheap = 0;

        for (int i = 0; i < qtdChurrascarias; i++) {
            int nota, pos;
            scanf("%d", &all[i].nota);
            if (sizeheap < qtdAmigos) {
                all[i].indice = insert(heap, all[i].nota, sizeheap);
                sizeheap++;
            } else {
                //printf ("retirar o: %d\n", all[i-qtdAmigos].nota);
                removeMin(heap, all[i-qtdAmigos].nota, qtdAmigos-1);
                all[i].indice = insert(heap, all[i].nota, qtdAmigos-1);
                if (i != qtdChurrascarias - 1) {
                    printf(" ");
                }
                else {
                    printf(" %d\n", heap[0]->nota);
                }
            }
        }
        for (int i = 0; i < qtdAmigos+1; i++) {
            free(heap[i]);
        }
        free(heap);
        free(all);
    }
    return 0;
}
