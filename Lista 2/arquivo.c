#include <stdio.h>

int main () {
    unsigned int total_items, search_page, items_per_page, id_item, lower_limit , upper_limit, count = 0;

    scanf("%u %u %u", &total_items, &search_page, &items_per_page);
    lower_limit = search_page * items_per_page;
    upper_limit = lower_limit + items_per_page;

    while (scanf("%u", &id_item) != EOF) {
        if (count >= lower_limit && count < upper_limit) {
            printf("%u\n", id_item);
        }
        count++;
    }

    return 0;
}