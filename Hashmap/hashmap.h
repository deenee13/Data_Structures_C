#include <stdio.h>
#include <stdlib.h>

// This struct contains key and value along with the next field
// to point to the valid node of hash
struct node {
    unsigned int key;
    unsigned int value;
    struct node *next;
};

// This struct is used to create the hashtable
// hence it contains size field along with it contains the
// Pointer to pointer variable pointing to the head of the
// Specific list
struct table {
    unsigned int size;
    struct node **list;
};

struct table *create_table(unsigned int size);

int hash_code(struct table *t, int key);

void insert(struct table *t, int key, int value);
int lookup(struct table *t, int key);
