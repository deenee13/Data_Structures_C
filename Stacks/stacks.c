#include <stdio.h>
#include <stdbool.h>


/*
        Operations with stack
        1) Push(element to be pushed)  // Function to push data in stack
        2) Pop()    // Function to pop data from stack
        3) Top()   // Function to know the top element of stack
        4) Isempty()    // Function to know whether the stack is empty or not

        We can implement stack using array and linked list in which we can remove and add the element from the head of the 
        linked list as to remove and delete the element from the head has o(1) time complexity.
        This is the reason I have not implemented it over here again.

        Visit my code school to see application of the stack
        Application: 
        1) Stack can be used to reverse a linked list.
        2) It can be used to check for the valid paranthesis and brackets. Also use to 
        solve some mathematical operation using it
        3) It can be used to reverse a linked list by storing the address of the node on to stack.
        and then retreving one address and changing the link of it.
        4) We can also print the linked list in reverse order using stack
        5) It can also be used to check for prefix and the postfix application 

**/


/** ARRAY BASED APPROACH **/

#define MAX_LENGTH 101

// Array Declaration for stack
int arr[MAX_LENGTH];

// Variable which will point top of stack
int top = -1;

// Function to push element into stack
void push(int x) {
    if (top == (MAX_LENGTH - 1)) {
        printf("Stack is full\n");
        return;
    } else {
        top++;
        arr[top] = x;
    }
}

// Function to pop top element from the stack
void pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    } else {
        top--;
    }
}

// Function to show Top element of the stack
int Top() {
    return(arr[top]);
}

// Function to check the status of the stack
bool isempty() {
    if (top == -1) {
        return true;
    } else {
        return false;
    }
}

// Print Stack

void print() {
    printf("Stack:  ");
    for (int i =0; i <= top; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}


int main(void) {
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


/////////////////////////////
//
//
// Implementation as linkedlist
//
/////////////////////////////

struct node {
    int value;
    struct node *next;
};

void push(int x);
void pop();

bool isempty();
int top_linkedlist();

struct node* front = NULL;

void push(int x) {

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->value = x;
    temp->next = NULL;

    if (front == NULL) {
        front = temp;
        return;
    }

    temp->next = front;
    front = temp;
}

void pop() {
    struct node *temp = front;

    if (top == NULL) {
        return;
    } else {
        front = front->next;
    }
    free(front);
}

bool isempty() {
    if (top == NULL) {
        return true;
    }

    return false;
}

int top_linkedlist() {
    return (front->value);
}


