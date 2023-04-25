/*
#include <stdio.h>
#include <stdlib.h>

struct EDA {
    char letter;
    int amount;
    int index;
} typedef info;

struct list {
    info data;
    struct list *next;
} typedef list;

list *insert (list *head, info data) {
    list *new = malloc(sizeof(list));
    new->data = data;

    if (head == NULL) {
        new->next = NULL;
        return new;
    }
    else {
        list *current = head;
        if (current->data.amount < data.amount) {
            new->next = current;
            return new;
        }
        while (current->next != NULL && current->next->data.amount >= data.amount) {
            current = current->next;
        }
        if (current->next == NULL) {
            new->next = NULL;
            current->next = new;
        }
        else {
            new->next = current->next;
            current->next = new;
        }
        return head;
    }
}


int main () {
    char current, previous = '1';
    int i = 0, count = 0;
    list *head = NULL;
    info data;

    while (scanf("%c", &current) != EOF) {
        if (current != previous && previous != '1') {
            data.letter = previous;
            data.amount = count;
            data.index = i - count;
            head = insert (head, data);
            count = 0;
        }
        count++; i++;
        previous = current;
    }
    data.letter = previous;
    data.amount = count;
    data.index = i - count;
    head = insert (head, data);

    for (list *current = head; current != NULL; current = current->next) {
        printf("%d %c %d\n", current->data.amount, current->data.letter, current->data.index);
    }        
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 52 // 26 letras maiúsculas e 26 letras minúsculas

typedef struct Node {
    char letter;
    int amount;
    int index;
    struct Node* next;
} Node;

typedef Node* hash[MAX_SIZE];

int hashFunction(char letter) {
    if (letter >= 'a' && letter <= 'z') {
        return letter - 'a';
    } else {
        return letter - 'A' + 26;
    }
}

void insert(hash hash_table, char letter, int count, int index) {
    int hash_index = hashFunction(letter);
    Node* new_node = malloc(sizeof(Node));
    new_node->letter = letter;
    new_node->amount = count;
    new_node->index = index;
    new_node->next = NULL;

    if (hash_table[hash_index] == NULL) {
        hash_table[hash_index] = new_node;
    } else {
        Node* current = hash_table[hash_index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void merge(Node **elements, int start, int mid, int end) {
    int left_size = mid - start + 1;
    int right_size = end - mid;

    Node *left[left_size];
    Node *right[right_size];

    int i, j, k;

    for (i = 0; i < left_size; i++) {
        left[i] = elements[start + i];
    }

    for (j = 0; j < right_size; j++) {
        right[j] = elements[mid + j + 1];
    }

    i = 0;
    j = 0;
    k = start;

    while (i < left_size && j < right_size) {
        if (left[i]->amount > right[j]->amount || (left[i]->amount == right[j]->amount && left[i]->index < right[j]->index)) {
            elements[k] = left[i];
            i++;
        } else {
            elements[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        elements[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size) {
        elements[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(Node **elements, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(elements, start, mid);
        merge_sort(elements, mid + 1, end);
        merge(elements, start, mid, end);
    }
}

void print_ordered(hash hash_table) {
    int count = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        for (Node* current = hash_table[i]; current != NULL; current = current->next) {
            count++;
        }
    }

    Node **elements = malloc(sizeof(Node *) * count);

    count = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        for (Node* current = hash_table[i]; current != NULL; current = current->next) {
            elements[count] = current;
            count++;
        }
    }

    merge_sort(elements, 0, count - 1);

    for (int i = 0; i < count; i++) {
        printf("%d %c %d\n", elements[i]->amount, elements[i]->letter, elements[i]->index);
    }

    free(elements);
}


int main () {
    char current, previous = '1';
    int i = 0, count = 0;
    hash hash_table = { NULL };

    while (scanf("%c", &current) != EOF) {
        if (current != previous && previous != '1') {
            insert(hash_table, previous, count, i - count);
            count = 0;
        }
        count++; i++;
        previous = current;
    }
    insert(hash_table, previous, count, i - count);

    print_ordered(hash_table);

    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 26

typedef struct Node {
    char letter;
    int amount;
    int index;
    struct Node* next;
} Node;

typedef Node* hash[MAX_SIZE];

int hashFunction(char letter) {
    if (letter >= 'a' && letter <= 'z') {
        return letter - 'a';
    } else if (letter >= 'A' && letter <= 'Z') {
        return letter - 'A' + 26;
    }
    return -1;
}

void insert(hash hash_table, char letter, int count, int index) {
    int hash_index = hashFunction(letter);
    Node* new_node = malloc(sizeof(Node));
    new_node->letter = letter;
    new_node->amount = count;
    new_node->index = index;
    new_node->next = NULL;

    if (hash_table[hash_index] == NULL) {
        hash_table[hash_index] = new_node;
    } else {
        Node* current = hash_table[hash_index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print(hash hash_table) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (Node* current = hash_table[i]; current != NULL; current = current->next) {
            printf("%d %c %d\n", current->amount, current->letter, current->index);
        }
    }
}

int main() {
    char current, previous = '1';
    int i = 0, count = 0;
    hash hash_table = { NULL };

    while (scanf("%c", &current) != EOF) {
        if (current != previous && previous != '1') {
            insert(hash_table, previous, count, i - count);
            count = 0;
        }
        count++; i++;
        previous = current;
    }
    insert(hash_table, previous, count, i - count);

    print(hash_table);

    return 0;
}
*/
