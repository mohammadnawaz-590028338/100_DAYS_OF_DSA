#include <stdio.h>
#include <string.h>

#define MAX 100

int table[MAX];
int m;

// initialize table
void init() {
    for (int i = 0; i < m; i++)
        table[i] = -1; // -1 means empty
}

// hash function
int hash(int key) {
    return key % m;
}

// insert using quadratic probing
void insert(int key) {
    int h = hash(key);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == -1) {
            table[index] = key;
            return;
        }
    }

    printf("Hash Table Full\n");
}

// search using quadratic probing
void search(int key) {
    int h = hash(key);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[index] == -1) {
            printf("NOT FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int q;
    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    init();

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key);
        }
    }

    return 0;
}
