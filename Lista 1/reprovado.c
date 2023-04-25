#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    int n, i, questoes, menor = -1, count = 1;
    char nome[20], reprovado[20];


    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++) {
            scanf("%s %d", nome, &questoes);
            if (menor == -1 || questoes < menor) {
                menor = questoes;
                strcpy(reprovado, nome);
            }
            else if (questoes == menor) {
                if (strcmp(nome, reprovado) > 0) {
                    strcpy(reprovado, nome);
                }
            }
        }
        printf("Instancia %d\n", count);
        printf("%s\n\n", reprovado);
        count++;
        menor = -1;
    }


    return 0;
}