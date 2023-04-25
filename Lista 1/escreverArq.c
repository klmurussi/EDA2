#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

int main () {
    FILE *arq = fopen ("arquivo.txt", "w");
    int i = 0;
    time_t t;
    fprintf (arq, "%d\n", MAX);
    srand((unsigned) time(&t));
    while (i < MAX) {
        fprintf (arq, "%d\n", rand() % MAX);
        i++;
    }
    
    fclose (arq);
    return 0;
}