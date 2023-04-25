#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define desfazer "desfazer"
#define inserir "inserir"

struct Linha{
    char texto[100];
    struct Linha *prox;
} typedef Linha;

void insere (Linha **lista, char *texto) {
    Linha *nova = malloc(sizeof(Linha));
    strcpy(nova->texto, texto);
    nova->prox = *lista;
    *lista = nova;
}

int main () {
    Linha *lista = NULL;
    char acao[10], linha[151], aux[151];
    while (scanf("%s", acao) != EOF) {
        if (strcmp(acao, desfazer) == 0) {
            if (lista == NULL) {
                printf("NULL\n");
            } else {
                printf("%s\n", lista->texto);
                lista = lista->prox;
            }
        } else if (strcmp(acao, inserir) == 0) {
            scanf("%[^\n]", linha);
            strcpy(aux, linha);
            strcpy(linha, aux+1);
            insere(&lista, linha);
        }
    }
    return 0;
}