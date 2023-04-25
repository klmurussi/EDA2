#include <stdio.h>
#include <stdlib.h>

struct seed {
    long long int cod;
    long int score;
} typedef SEED;

#define MIN -1000000

void mergeSort (SEED *v, long int start, long int end) {
    long int middle = (start + end) / 2;
    long int i = start, j = middle + 1, k = 0;
    SEED *aux = malloc((end - start + 1) * sizeof(SEED));

    if (start >= end) return;

    mergeSort(v, start, middle);
    mergeSort(v, middle + 1, end);

    while (i <= middle && j <= end) {
        if (v[i].cod < v[j].cod) {
            aux[k] = v[i];
            i++;
        } else {
            aux[k] = v[j];
            j++;
        }
        k++;
    }

    while (i <= middle) {
        aux[k] = v[i];
        i++;
        k++;
    }

    while (j <= end) {
        aux[k] = v[j];
        j++;
        k++;
    }

    for (i = start; i <= end; i++) {
        v[i] = aux[i - start];
    }

    free(aux);
}

int main () {
    SEED seed;
    SEED *selected;
    long int k, count = 0, highest = MIN, i = 0;
    char line[100];

    scanf("%ld", &k);
    selected = malloc(k * sizeof(SEED));

    while (count < k) {
        scanf("%lld %ld", &selected[count].cod, &selected[count].score);
        if (selected[count].score > highest || (selected[count].score == highest && selected[count].cod < selected[i].cod)) {
            highest = selected[count].score;
            i = count;
        }
        count++;
    }

    while (fgets(line, sizeof(line), stdin)) {
        sscanf(line, "%lld %ld", &seed.cod, &seed.score);
        //printf ("LIDO: %lld %ld\n", seed.cod, seed.score);
        if (seed.score < highest || (seed.score == highest && seed.cod < selected[i].cod)) {
            //printf ("%ld é menor que %ld ou %lld é menor que %lld\n", seed.score, highest, seed.cod, selected[i].cod);
            selected[i].cod = seed.cod;
            selected[i].score = seed.score;
            highest = selected[i].score;
            for (count = 0; count < k; count++) {
                if (selected[count].score > highest || (selected[count].score == highest && selected[count].cod > selected[i].cod)) {
                    highest = selected[count].score;
                    i = count;
                }
            }
            //printf ("%lld %ld é o novo maior\n", selected[i].cod, highest);
        } 
    }

    mergeSort(selected, 0, k - 1);

    for (count = 0; count < k; count++) {
        printf ("%lld %ld\n", selected[count].cod, selected[count].score);
    }

    return 0;
}