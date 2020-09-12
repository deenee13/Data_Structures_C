// Inserting a node at Nth Position in linked list, deleting Nth
// node and also reversing the linked list 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

struct node{
int data;
struct node* next;
};

/* Function Declaration  */
// Function to insert a node at nth location
struct node* insert(int data, int position, struct node *head);
// Function to insert node at back of the linked list
struct node* insert_tail(int data, struct node *head);
// Function to delete a node at nth location
struct node* delete(int position, struct node *head);
// Function to reverse a linked list
struct node* reverse(struct node *head);
// Function to reverse a linked list using recursion
struct node* reverse_recursion(struct node *head);
// Function to print the linked list
void print(struct node *head);
// Function to merge two sorted list
struct node* merge_two_lists(struct node* l1, struct node* l2);




struct node* merge_two_lists(struct node* l1, struct node* l2) {
    // Creating a new temp variabe to merge the list
    struct node* temp = NULL;
    while (l1 != NULL || l2 != NULL) {
        // Extract the first element of both the lists
        if (l2->data < l1->data) {
            temp = insert_tail(l2->data, temp);
            temp = insert_tail(l1->data, temp);
        } else  {
            temp = insert_tail(l1->data, temp);
            temp = insert_tail(l2->data, temp);
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    return temp;
}

// Function to insert node at back of the linked list
struct node* insert_tail(int data, struct node *head) {
    struct node* temp = head;
    // Create a new node using malloc
    struct node* temp1 = (struct node*) malloc(sizeof(struct node));
    // Assign data to it and set the next field as NULL
    temp1->data = data;
    temp1->next = NULL;
    // If list is NULL
    if (head == NULL) {
        head = temp1;
        return (head);
    }
    // Go till the last position in the linked list
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = temp1;
    return head;
}

// Function to insert a node at nth location
struct node* insert(int data, int position, struct node *head) {
    struct node* temp1 = (struct node*) malloc(sizeof(struct node));
    temp1->data = data;
    temp1->next = NULL;

    if (position == 1) {
        temp1->next = head;
        head = temp1;
        return(head);
    }

    struct node *temp2 = head;

    // this for loop will take you to n-1 location to get the link proper
    // remember it is staritng fromn 0 that is why it is
    // going till n-2 and not n-1
    // don't get confuse because of that
    for (int i = 0; i < (position - 2); i++) {
        temp2 = temp2->next;
    }
    // First save the value of (n-1)th node next field
    // into our newly creted node->next field
    // Then store the address of the newly created node
    // in to the (n-1)th->next field to get the link proper
    temp1->next = temp2->next;
    temp2->next = temp1;
    return(head);
}

// Function to delete a node at nth location
struct node* delete(int position, struct node *head) {
    struct node* temp1 = head;
    if (position == 1) {
        // Link has been established as head stores
        // the address of the second node
        head = temp1->next;
        free(temp1);
        return(head);
    }

    // this for loop will take you to n-1 location to get the link proper
    // remember it is staritng fromn 0 that is why it
    // is going till n-2 and not n-1
    // don't get confuse because of that
    for (int i = 0; i < (position - 2); i++) {
        temp1 = temp1->next;
    }

    struct node* temp2 = temp1->next;  // To go ot the nth node
    temp1->next = temp2->next;  // (n + 1)th node

    // To free the space
    free(temp2);
    return(head);
}

// Function to reverse a linked list
struct node* reverse(struct node *head) {
    struct node* current;
    // To store the value of the previous node to reverse the list
    struct node* prev;
    // to store the value of the next node to prevent loss of the address
    struct node* next;

    current = head;
    prev = NULL;

    while (current != NULL) {
        // First we will store the next field of current node
        // as the address of the next node
        next = current->next;

        // Then we will update the current node's next field with the previous
        // field which we have set at null over here
        current->next = prev;

        // Then we will update the prev and the current struct node
        // to move forward and repeat the process
        // by doing below statement we are basically changing the address
        // of the particular node to point to specific location
        prev = current;
        current = next;
    }

    // To adjust the head of the linked list most important step
    head = prev;
    return(head);
}


// Function to reverse a linked list using recursion
struct node* reverse_recursion(struct node *head) {
    struct node* temp;
    if (head->next == NULL) {
        temp = head;
        return(temp);
    }
    reverse_recursion(head->next);
    struct node* q = head->next;
    q->next = head;
    head->next = NULL;
    return(temp);
}

// Function to print the linked list
void print(struct node*head) {
    struct node *temp = head;
    printf("List:");
    while (temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


// You could also take values from the user
int main() {
    int position;

    struct node *head = NULL;    // empty list

    
    head = insert_tail(2, head);    // list: 2
    head = insert_tail(3, head);    // list: 2,3
    head = insert_tail(4, head);    // list: 2,3,4
    head = insert_tail(5, head);    // list: 2,3,4,5
    /*
    head = insert(2, 1, head);    // list: 2
    head = insert(3, 2, head);    // list: 2,3
    head = insert(4, 1, head);    // list: 4,2,3
    head = insert(5, 2, head);    // list: 4,5,2,3
    printf("Complete linked list before deletion\n");
    */
    print(head);

    // Reversing a linked list
    printf(" Linked list after reversing it\n");
    head = reverse(head);
    print(head);

    printf("Value of position to be deleted: ");
    scanf("%d", &position);

    head = delete(position, head);
    printf("Complete linked list after deletion\n");
    print(head);
}