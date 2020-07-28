#include <stdio.h>
#include <stdbool.h>


/*
        Operations with Queue
        1) Enqueue(element to be pushed)  // Function to push data in queue
        2) Dequeue()    // Function to pop data from queue
        3) Front()   // Function to know the top element of queue
        4) Isempty()    // Function to know whether the queue is empty or not

        We can implement queue using array and linked list 

**/



int front = -1;
int rear = -1;


int main()
{
    unsigned int num_length = 0;
    printf("Enter the length of the queue:");
    scanf(" %d ", &num_length);
}



// Function to check whether queue is full or not
bool isempty()
{
    if(front == -1 && rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }  
}

// 

// Function to Enqueue data in the queue

int enqueue(int x)
{
    if (isfull() == true)
    {
        return;
    }
}