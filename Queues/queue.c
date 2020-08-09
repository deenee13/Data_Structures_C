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

struct node{
    int data;
    struct node* next;
};

// Global Declaration 
struct node* front = NULL;
struct node* rear = NULL;



// Function Declaration
void enqueue(int x); // To add element from the queue
void dequeue(); // To remove element from the queue
void print(); // Function to print the linked list 



void dequeue()
{
    // It is created to delete the memory from heap
    struct node* temp = front;

    if(front == NULL)
    {
        return;
    }
    if(front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
    }
    
    free(temp);
}


void enqueue(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node*));
    temp->data = x;
    temp->next = NULL;

    if(front == NULL && rear == NULL)
    {
        rear = temp;
        front = temp;
        return;
    }

    // Try to implement this logic on paper and it will be more clear
    rear->next = temp;
    rear = temp;
}

// Function to print the linked list 
void print()
{
    struct node* temp = front;
    printf("List:");
    while(front != NULL)
    {
        printf(" %d ", front->data);
        front = front->next;
    }
    printf("\n");

}


int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    dequeue();
    print(); // Expected output = 20 30 40 50 
}