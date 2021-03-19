#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Declaring a node. */
struct node {
    int data;
    struct node* next;
};

/* Declaring a struct of two stacks. */
struct queue {
    struct node* stack1;
    struct node* stack2;
};

/* Function Declaration for stack Implementation. */
void push(struct node** front, int data);
int pop(struct node** front);
/* Function Declaration for Queue Implementation. */
void enqueue(struct queue* q, int data);
int dequeue(struct queue* q);

/*  
 *  Making dequeue operation costly. If stack2 is empty then transfer all
 *  the elements from s1 to s2. Then pop top element from the stack 2.
 *  If not empty then simply pop element from it.
 */
int dequeue(struct queue* q) {
    int data;
    if (q->stack2 == NULL) {
        while (q->stack1 != NULL) {
            data = pop(&q->stack1);
            push(&q->stack2, data);
        }
    }

    data = pop(&q->stack2);
    return data;
}

/*
 * In Enqueue operation simply push to stack 1 normally. 
 */
void enqueue(struct queue* q, int data) {

    /* In enqueue function I am simply pushing the data in stack 1. */
    push(&q->stack1, data);
}

/* Normal stack push implementation. */
void push(struct node** front, int data) {

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = *front;

    *front = newnode;
}

/* Normal stack pop implementation. */
int pop(struct node** front) {
    
    int data;
    if (*front == NULL) {
        printf("Empty\n");
        return 0;
    } else {
        struct node* temp = *front;
        data = temp->data;
        *front = (*front)->next;
        free(temp);
        return data;
    }
}


int main(void) {

    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->stack1 = NULL;
    q->stack2 = NULL;

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40); // ->> 10 20 30 40

    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q)); // ->> 30 40

    return 0;
}