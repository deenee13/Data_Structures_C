#include "hashmap.h"

// This function will create the table depending upon the size
struct table *create_table(unsigned int size) {
    // This will pass on the pointer to the first location to our table
    struct table *t = (struct table*)malloc(sizeof(struct table));

    // Storing the size of the table in the size variable
    t->size = size;

    // It will pass on pointer to the head of the list
    t->list = (struct node**)malloc(size*sizeof(struct node*));

    // For loop to make them NULL
    for (int i=0; i < size; i++) {
        // Doubt ask mamu
        t->list[i] = NULL;
    }
    return t;
}

// It will return the position in out hash table
// where our key value can be store
int hash_code(struct table *t, int key) {
    if (key < 0) {
        return -(key % t->size);
    } else {
        return (key % t->size);
    }
}

// It will insert the key value pair into the
// specific location in our table
void insert(struct table *t, int key, int value) {
    // This will give us the location where we need to add our new entry
    int position = hash_code(t, key);

    // Passing the address of the head to the list
    struct node *list = t->list[position];

    // Creating a temp variable to iterate through the list;
    struct node *temp = list;

    // Iterating through the specific list
    while (temp) {
        // If the key is already present update the value
        if (temp->key == key) {
            temp->value = value;
            return;
        }
        temp = temp->next;
    }

    // Creating a new node to store the new entry
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    // If the key is not present then add the entry
    // at the front of the list and update the head
    newnode->key = key;
    newnode->value = value;

    // Updating the address of the previous entry by entering
    // it into the next field of the new node
    newnode->next = list;

    // Updating the array of heads
    t->list[position] = newnode;
}

// Function to find the specific value from the hashmap
int lookup(struct table *t, int key) {
    int pos = hash_code(t, key);
    struct node *list = t->list[pos];
    struct node *temp = list;
    while (temp) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}


int main(void) {
    struct table *t = create_table(5);
    insert(t, 2, 3);
    insert(t, 5, 4);
    printf("%d\n", lookup(t, 5));
    return 0;
}
