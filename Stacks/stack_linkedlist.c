#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

void push(int x);
void pop();
int isempty();
int top();

// Global Variable for the stack
struct node *front = NULL;

void push(int x) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = front;

    front = temp;
}

void pop() {
    if (front == NULL) {
        return;
    }
    struct node *temp = front;
    front = front->next;
    free(temp);
}

int isempty() {
if (front == NULL) {
    return true;
}
return false;
}

int top() {
    if (front == NULL) {
        return false;
    } else {
        return (front->data);
    }
}

void print() {
    printf("Data in stack is:\n");
    while (front != NULL) {
        printf("%d\n", front->data);
        front = front->next;
    }
}

int main(void) {
    bool rc;
    push(2);
    push(3);
    rc = isempty();
    push(4);
    pop();
    print();
    printf("Value of rc is %d\n", rc);
}
