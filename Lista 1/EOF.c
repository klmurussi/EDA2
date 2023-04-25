#include <stdio.h>

int main (int argc, char *argv[]) {
    int qtd = 0, n;
    
    while (scanf ("%d", &n) != EOF) qtd++;

    printf ("%d\n", qtd);
    return 0;
}