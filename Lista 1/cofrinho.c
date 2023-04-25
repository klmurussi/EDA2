#include <stdio.h>

int main () {
    int N, i, a, b, c, teste = 1;

    while (scanf("%d", &N) != EOF) {
        if (N == 0) break;
        int Joao = 0, Ze = 0;
        printf ("Teste %d\n", teste++);
        for (i = 0; i < N; i++) {
            scanf("%d %d", &a, &b);
            Joao += a;
            Ze += b;
            c = Joao - Ze;
            printf ("%d\n", c);
        }
        printf ("\n");
    }

    return 0;
}