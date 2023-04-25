#include <stdio.h>
#include <stdlib.h>

struct restaurante {
    long int cod_restaurante;
    struct restaurante *prox;
} typedef R;

int main () {
    int n_restaurante, count = 0;
    long int cod_restaurante;
    int nota_restaurante;
    long int nota_restauranteS[6];
    R *restaurantes = NULL;

    while (scanf("%d", &n_restaurante) != EOF) {
        for (int i = 0; i < 6; i++) {
            nota_restauranteS[i] = -1;
        }
        for (int i = 0; i < n_restaurante; i++) {
            scanf("%ld %d", &cod_restaurante, &nota_restaurante);
            if (nota_restauranteS[nota_restaurante] == -1) {
                nota_restauranteS[nota_restaurante] = cod_restaurante;
            }
            else if (nota_restauranteS[nota_restaurante] > cod_restaurante) {
                nota_restauranteS[nota_restaurante] = cod_restaurante;
            }
        }
        for (int i = 5; i >= 0; i--) {
            if (nota_restauranteS[i] != -1) {
                // inserir no fim da lista
                R *novo = (R*) malloc(sizeof(R));
                novo->cod_restaurante = nota_restauranteS[i];
                novo->prox = NULL;
                if (restaurantes == NULL) {
                    restaurantes = novo;
                }
                else {
                    R *aux = restaurantes;
                    while (aux->prox != NULL) {
                        aux = aux->prox;
                    }
                    aux->prox = novo;
                }
                count++;
                break;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("Dia %d\n%ld\n\n", i+1, restaurantes->cod_restaurante);
        restaurantes = restaurantes->prox;
    }

    return 0;
}