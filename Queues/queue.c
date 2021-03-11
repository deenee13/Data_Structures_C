#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


/*
        Operations with Queue
        1) Enqueue(element to be pushed)  // Function to push data in queue
        2) Dequeue()    // Function to pop data from queue
        3) Front()   // Function to know the top element of queue
        4) Isempty()    // Function to know whether the queue is empty or not

        We can implement queue using array and linked list 

**/


/* Implementation of queue using linked list */

typedef struct node {
    int data;
    struct queue* next;
}queue;

// Global Declaration
queue* front = NULL;
queue* rear = NULL;


// Function Declaration
void enqueue(int x);  // To add element from the queue
void dequeue();  // To remove element from the queue
int isempty(void);
int peek();
void print();  // Function to print the linked list



void dequeue() {
    // It is created to delete the memory from heap
    queue* temp = front;
    int num;

    if (front == NULL) {
        return;
    }
    if (front == rear) {
        front = NULL;
        rear = NULL;
    } else {
        num = front->data;
        front = front->next;
    }
    free(temp);
    printf("Value of num: %d\n", num);
}


void enqueue(int x) {
    queue* temp = (struct node*)malloc(sizeof(queue));
    temp->data = x;
    temp->next = NULL;

    if (front == NULL && rear == NULL) {
        // Remember storing the address of temp in both rear and front.
        // Hence we can access node by modifying both of them.
        rear = temp;
        front = temp;
        return;
    }

    // Try to implement this logic on paper and it will be more clear
    // Updating the next field of the specific node as rear points to the
    // Address of the last node in the linked list

    // making the link for the queue
    // So that front can use it to remove element from the queue
    rear->next = temp;
    // Updating the value of the rear to point it to the end of the linked list
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

// Function to print the linked list
void print() {
    printf("List:");
    while (front != NULL) {
        printf(" %d ", front->data);
        front = front->next;
    }
    printf("\n");
}


int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    dequeue();
    print();  // Expected output = 20 30 40 50
}
