#include <stdio.h>
#include <stdbool.h>

// Change the data type of key depending upon the key you want
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

bool insert(struct table *t, int key, int value);


struct table *create_table(unsigned int size) {
    // This will pass on the pointer to the first location to our table
    struct table *t = (struct table*)malloc(sizeof(struct table));

    // Storing the size of the table in the size variable
    t->size = size;

    // It will pass on pointer to the head of the list
    t->list = (struct node**)malloc(size*sizeof(struct node*));

    // For loop to make them NULL
    for (int i = 0; i < size; i++) {

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
bool insert(struct table *t, int key, int value) {
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
            if (temp->value != value) {
                return false;
            }
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

    return true;
}



bool isIsomorphic(char * s, char * t) {

    if (s == NULL || t == NULL) {

        return false;
    }

    struct table *structure = create_table(5);
    int i = 0;
    int rc = 0;
    while (*(s + i) != '\0' && *(t + i) != '\0') {
        rc = insert(structure, *(s + i), *(t + i));

        if (rc == false) {
            return false;
        }

        //// I Think I forgot to implemented this
        //// due to which I was getting stuck in the
        //// While loop
        i++;
    }
    return true;
}
