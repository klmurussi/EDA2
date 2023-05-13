#include <stdio.h>
#include <stdlib.h>

unsigned int partition(unsigned int *arr, unsigned int left, unsigned int right, unsigned int pivotIndex) {
    unsigned int pivotValue = arr[pivotIndex];
    unsigned int temp = arr[right];
    arr[right] = arr[pivotIndex];
    arr[pivotIndex] = temp;
    unsigned int storeIndex = left;
    for (unsigned int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            temp = arr[i];
            arr[i] = arr[storeIndex];
            arr[storeIndex] = temp;
            storeIndex++;
        }
    }
    temp = arr[storeIndex];
    arr[storeIndex] = arr[right];
    arr[right] = temp;
    return storeIndex;
}

unsigned int quickselect(unsigned int *arr, unsigned int left, unsigned int right, unsigned int k) {
    while (1) {
        if (left == right) {
            return arr[left];
        }
        unsigned int pivotIndex = left + rand() % (right - left + 1);
        pivotIndex = partition(arr, left, right, pivotIndex);
        if (k == pivotIndex) {
            return arr[k];
        } else if (k < pivotIndex) {
            right = pivotIndex - 1;
        } else {
            left = pivotIndex + 1;
        }
    }
}


int main() {
    unsigned int total_items, search_page, items_per_page, *id_item, lower_limit , upper_limit, qs;

    scanf("%u %u %u", &total_items, &search_page, &items_per_page);
    id_item = (unsigned int *) malloc(total_items * sizeof(unsigned int));
    lower_limit = search_page * items_per_page;
    upper_limit = lower_limit + items_per_page;
    
    for (unsigned int i = 0; i < total_items; i++) {
        scanf("%u", &id_item[i]);
    }

    qs = quickselect(id_item, 0, total_items - 1, upper_limit);
    upper_limit = qs;
    qs = quickselect(id_item, 0, total_items - 1, lower_limit);
    lower_limit = qs;

    for (unsigned int i = 0; i < total_items; i++) {
        if (id_item[i] >= lower_limit && id_item[i] < upper_limit) {
            printf("%u\n", id_item[i]);
        }
    }

    free(id_item);
    return 0;
}
