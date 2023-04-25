/* #include <stdio.h>
#include <stdlib.h>

struct registro {
    int valor;
    struct registro *prox;
} typedef Registro;

int main () {
    long int qtd, i, j, count = 0;

    scanf("%ld", &qtd);

    Registro *registro = NULL;

    for (i = 0; i < qtd; i++) {
        int verdadeiro = 0;
        scanf("%d", &registro[i].valor);
        for (j = 0; j < i; j++) {
            if (registro[i] == registro[j]) {
                verdadeiro = 1;
                break;
            }
        }
        if (verdadeiro == 0) {
            count++;
        }
    }
    printf("%ld\n", count);
    free(registro);
}*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int main () {
    long int tam, i, count = 0, aux;
    long int *lista = calloc (MAX, sizeof(long int));

    scanf("%ld", &tam);
    for (i = 0; i < tam; i++) {
        scanf("%ld", &aux);
        if (lista[aux] == 0) {
            lista[aux] = 1;
            count++;
        }
    }
    free (lista);
    printf("%ld\n", count);
    return 0;
}