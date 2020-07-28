#include <stdio.h>
#include <stdbool.h>


/*
        Operations with stack
        1) Push(element to be pushed)  // Function to push data in stack
        2) Pop()    // Function to pop data from stack
        3) Top()   // Function to know the top element of stack
        4) Isempty()    // Function to know whether the stack is empty or not

        We can implement stack using array and linked list 

**/


/** ARRAY BASED APPROACH **/

#define MAX_LENGTH 101

// Array Declaration for stack
int arr[MAX_LENGTH];

// Variable which will point top of stack
int top = -1;

// Function to push element into stack

void push(int x)
{
    if(top == (MAX_LENGTH - 1))
    {
        printf("Stack is full\n");
        return;
    }
    else
    {
        top++;
        arr[top] = x;
    }
    
}

// Function to pop top element from the stack
void pop()
{
    if( top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        top--;
    }
}

// Function to show Top element of the stack 
 int Top()
 {
     return(arr[top]);
 }


// Function to check the status of the stack
bool isempty()
{
    if(top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

// Print Stack

void print()
{
    printf("Stack:  ");
    for (int i =0; i <= top; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}


int main() {	
  // Code to test the implementation. 
  // calling Print() after each push or pop to see the state of stack. 
	push(2);
    print();
	push(5);
    print();
	push(10);
    print();
	pop();
    print();
	push(12);
    print();
}