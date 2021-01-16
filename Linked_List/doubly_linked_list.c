// Implementation of the Doubly Linked list

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

// Function Declaration
struct node* insert_head(int data, struct node* head);  // Insert node at head
struct node* get_new_node(int x);   // Function to create a new node
void print_forward(struct node *head);  // Print Function in forward directiom
void print_reverse(struct node *head);  // Print function in reverse direction



// Function to create new node
struct node* get_new_node(int x) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    return(newnode);
}

// Function to insert new node at head
struct node* insert_head(int x, struct node* head) {
    struct node* newnode;
    newnode = get_new_node(x);
    ////  printf("In insert head function\n");

    // This if statement is important over here as if the
    // list is empty then we will
    // access the prev location first in this function
    // which will give segmentation fault
    if (head == NULL) {
        head = newnode;
        return(head);
    }

    /* Due to this line above if statement is important 
     as this is not there in single linked list. Above if statement
     in single linked list can be eliminated */

    // As head is pointing to the first location in the list
    // By doing this we are storing the address of the new node
    // in the previous space to build reverse link
    head->prev = newnode;

    // By doing this I am building the forward link by storing previous 1st node
    // address in the newnode next location
    newnode->next = head;

    // Then changing the address of the head with newnode
    head = newnode;
    //// printf("Out of Insert head function\n");
    return(head);
}

// Function to print linked list in forward direction
void print_forward(struct node* head) {
  printf("Forward List is: ");
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

// Function to print linked list in reverse direction
void print_reverse(struct node* head) {
    if (head == NULL) {
        return;
    }
    while (head->next != NULL) {
        head = head->next;
    }

    printf("Reverse List is: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}



int main() {
    struct node* head = NULL;   // Why is this statement so important
    // printf("Addres of the *node head: %d\n",head);
    head = insert_head(1, head);  // Expected output: 1
    head = insert_head(2, head);  // Expected output: 2 1
    head = insert_head(3, head);  // Expected output: 3 2 1
    print_forward(head);        // Expected output: 3 2 1
    print_reverse(head);        // Expected output: 1 2 3
}
