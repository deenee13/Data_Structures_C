#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* next;
};

int enqueue(struct node** front, struct node** rear, int data);
int dequeue(struct node** front, struct node** rear);
int peek(struct node* front, struct node* rear);
bool isempty(struct node* front, struct node* rear);
void print(struct node** front);


int enqueue(struct node** front, struct node** rear, int data) {

    /* Creating a newnode. */
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    /*  Initial Condition.  */
    if (*front == NULL && *rear == NULL) {

        *front = newnode;
        *rear = newnode;
        return 1;
    }

    /*  Regular Condition.  */

    /*
     *  Creating a temporary variable temp to
     *  add the newnode's address in the next field.
     */
    struct node* temp = *rear;
    temp->next = newnode;       /* *rear->next = newnode; */

    /*
     *  Updating the address of the rear with the
     *  newnode to. To make sure that rear points
     *  to the recently added node. 
     */
    *rear = newnode;        /* temp = newnode; */

    return 1;
}


int dequeue(struct node** front, struct node** rear) {

    /*  Storing the  address of the front node in temp variable. */
    struct node* temp = *front;

    /*  Regular check. */
    if (*front == NULL && *rear == NULL) {
        return 0;
    }

    /* If both are equal reintialise them to NULL.  */
    if (*front == *rear) {
        *front = NULL;
        *rear = NULL;
        return 1;
    } else {
        /*
         *  Updating the address of the front to point the 
         *  next valid node in the queue.
         */
        *front  = temp->next;
    }
    /* Deallocating the memory. */
    free(temp);

    return 1;
}

int peek(struct node* front, struct node* rear) {

    if (front != NULL && rear != NULL) {
        return front->data;
    } else {
        return 0;
    }
}

bool isempty(struct node* front, struct node* rear) {

    if (front == NULL && rear == NULL) {
        return true;
    } else {
        return false;
    }
}

void print(struct node** front) {
    //  struct node* temp = *front;
    *front = (*front)->next;
    printf("In print\n");

    while (*front) {

        printf("%d\n", (*front)->data);
        *front = (*front)->next;
    }
}


// <TODO:> Do proper testing Later
// <TODO:> Not checking the return value.
// Could be used to check what is the status of the queue
int main(void) {

    struct node* front = NULL;
    struct node* rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 40);

    dequeue(&front, &rear);
    dequeue(&front, &rear);


    print(&front);
    int data = peek(front, rear);
    printf("Peek data: %d\n", data);

    bool value = isempty(front, rear);
    printf("Value: %d", value);

}

