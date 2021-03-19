#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int push(struct node** front, int data);
int pop(struct node** front);
bool isempty(struct node* front);
int istop(struct node* front);


int push(struct node** front, int data) {

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = *front;

    *front = newnode;
    return 0;
}

int pop(struct node** front) {

    struct node* temp = *front;
    if (*front == NULL) {
        return 1;
    } else {
        *front = temp->next;
    }
    free(temp);
    return 0;
}

bool isempty(struct node* front) {
    if (front != NULL) {
        return false;
    } else {
        return true;
    }
}

int top(struct node* front) {

    if (front != NULL) {
        return ((front)->data);
    } else {
        return -1;
    }
}

void print(struct node** front) {

    struct node* temp = *front;

    while (*front) {

        printf("%d\n", (*front)->data);
        *front = (*front)->next;
    }
}


int main(void) {
    struct node* front = NULL;
    int rc = 0;
    rc = push(&front, 10);
    rc = push(&front, 20);
    rc = push(&front, 30);
    rc = push(&front, 40);
    rc = push(&front, 50);
    rc = pop(&front);
    print(&front);   //40 30 20 10
}