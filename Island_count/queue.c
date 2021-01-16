#include "queue.h"

/* Function  for Queue*/

void dequeue() {
    // It is created to delete the memory from heap
    struct node* temp = front;
    if (front == NULL) {
        return;
    }
    if (front == rear) {
        front = NULL;
        rear = NULL;
    } else {
        front = front->next;
    }
    free(temp);
}

void enqueue(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node*));
    temp->data = x;
    temp->next = NULL;

    if (front == NULL && rear == NULL) {
        rear = temp;
        front = temp;
        return;
    }

    // Try to implement this logic on paper and it will be more clear
    rear->next = temp;
    rear = temp;
}

int isempty(void) {
    if ( front == NULL && rear == NULL ) {
        return(1);
    } else {
        return(0);
    }
}


int peek() {
    // Check for the empty Queue
    if (front != NULL) {
        return(front->data);
    } else {
        printf("Queue is empty exiting the code\n");
        exit(EXIT_FAILURE);
    }
}
