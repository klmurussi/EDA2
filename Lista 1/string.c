#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    int n, soma, j;
    char linha[100];

    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        soma = 0;
        scanf ("%s", linha);
        int *array = calloc(26, sizeof(int));
        for (j = 0; j < strlen(linha); j++) {
            if (linha[j] >= '0' && linha[j] <= '9') {
                soma += linha[j] - '0';
            }
        }
        printf ("%d\n", soma);
    }

    return 0;
}