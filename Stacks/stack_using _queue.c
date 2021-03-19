#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* next;
};

struct queue {
    struct node* front;
    struct node* rear;
};

struct stack {
    struct queue* q1;
    struct queue* q2;
};

/* Queue Implementation. */
void enqueue(struct queue* q1, int data);
int dequeue(struct queue* q2);
/* Stack Implementation. */
void push(struct stack* s1, int data);
int pop(struct stack* s1);

/* Normal Enqueue operation. */
void enqueue(struct queue* q1, int data) {

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (q1->front == NULL && q1->rear == NULL) {
        q1->front = newnode;
        q1->rear = newnode;
        return;
    }

    q1->rear->next = newnode;
    q1->rear = newnode;
}

/* Normal Dequeue operation. */
int dequeue(struct queue* q1) {

    struct node* temp = q1->front;
    int data = q1->front->data;
    if (q1->front == q1->rear) {
        q1->front = NULL;
        q1->rear = NULL;

    } else {
        q1->front = q1->front->next;
    }
    free(temp);
    return data;
}

/* In push function just push the data using Enqueue.*/
void push(struct stack* s1, int data) {

    struct queue* q1 = s1->q1;
    enqueue(q1, data);
}

/* This is where Fun begins. */

/*
 * If there are n elements in q1 then transfer
 * n-1 elements from q1 to q2. As we are interested
 * in nth element over here. Pop that element out.
 * 
 * swap the addresses of both the queues.
 * hence using q2 as a temporary queue over here.
 */
int pop(struct stack* s1) {

    struct queue* q1 = s1->q1;
    struct queue* q2 = s1->q2;
    struct queue* q;
    int data;

    if (q1->front == NULL && q1->rear == NULL) {
        printf("stack is empty\n");
        return 0;
    }

    /* Transferring n-1 elements from q1 to q2. */
    while (q1->front != q1->rear) {
        data = dequeue(q1);
        enqueue(q2, data);
    }

    /* Removing nth(top) element from the stack. */
    data = dequeue(q1);

    /*
     * Swapping the addresses of both the Queue. 
     * 
     * remember :   q = q1;
     *              q1 = q2;
     *              q2 = q; 
     * will not swap the address from the main struct of queues from the stack struct. 
     * Common error avoid it.
     */    
    q = q1;
    s1->q1 = q2;
    s1->q2 = q;

    return data;
}


void print(struct stack* s1) {

    struct queue* q1 = s1->q1;

}

/* <TODO:> Testing is remaining. */
int main(void) {

    /* Allocating memory for stack1 which contains declaration of both the queues. */
    struct stack* s1 = (struct stack*)malloc(sizeof(struct stack));

    s1->q1 = (struct queue*)malloc(sizeof(struct queue));
    s1->q2 = (struct queue*)malloc(sizeof(struct queue));
    
    /* Initialising queue1. */
    s1->q1->front = NULL;
    s1->q1->rear = NULL;

    /* Initialising queue2. */
    s1->q2->front = NULL;
    s1->q2->rear = NULL;

    
    push(s1, 10);
    push(s1, 20);
    push(s1, 30);
    push(s1, 40); // ->> 40 30 20 10

    printf("popped value = %d\n", pop(s1)); // ->> 30 20 10
    push(s1, 50); // ->> 50 30 20 10
    printf("popped value = %d\n", pop(s1)); // ->> 30 20 10
    printf("popped value = %d\n", pop(s1)); // ->> 20 10
    printf("popped value = %d\n", pop(s1)); // ->> 10
    printf("popped value = %d\n", pop(s1)); // ->> 0
    printf("popped value = %d\n", pop(s1)); // ->> stack is empty

    push(s1, 10); // ->> 10
    push(s1, 20); // ->> 20 10
    push(s1, 30); // ->> 30 20 10

    printf("popped value = %d\n", pop(s1)); // ->> 20 10
}


