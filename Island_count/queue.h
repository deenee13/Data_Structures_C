#include <stdio.h>
#include <stdlib.h>


struct node* front = NULL; // Flag for Queue Implementation
struct node* rear = NULL; // Flag for Queue Implementation


// Functions for Queue Implementation
void enqueue(int x);     // To add element from the queue
void dequeue();          // To remove element from the queue
int isempty(void);           // Function to check whether queue is empty or not
int peek();