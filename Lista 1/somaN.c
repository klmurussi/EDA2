#include <stdio.h>

int main () {
    int qtd, n;
    long long int soma = 0;

    scanf ("%d", &qtd);
    for (int i = 0; i < qtd; i++) {
        scanf ("%d", &n);
        soma+=n;
    }

    printf ("%lld\n", soma);
    return 0;
}