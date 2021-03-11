#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define sizeofdeep(type) (char*)(&type+1) - (char*)(&type)

struct node {
    int data;
    struct node* next;
};

void enqueue(int data);
void dequeue();
int top();
bool isempty();

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int data) {

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = newnode;
        rear = newnode;
        return;
    }

    rear->next = newnode;
    rear = newnode;
}

void dequeue() {

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

int peek() {

    if (front != NULL) {
        return front->data;
    } else {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
}

bool isempty() {
    if (front == NULL && rear == NULL) {
        return true;
    } else {
        return false;
    }
}

void print() {
    printf("List:");
    while (front != NULL) {
        printf(" %d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main(void) {
    /*
    int i = 0;

    int  *restrict ptr = &i;

    int *restrict ptr1 = &i;

    *ptr = 5;


    int *pointer = NULL;

    const int * var = NULL;

    pointer = (int*) var;

    long int * ptr = (long int*)malloc(sizeof(int));
    long int var = 0;
    ptr = &var;
    printf("address of ptr is %d value is %d and &var = %d\n", &ptr, ptr, &var);
    // printf("value of i is %d and ++i %d", i, ++i);
    */
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    dequeue();
    print();  // Expected output = 20 30 40 50
}
