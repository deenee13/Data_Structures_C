#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 10

int init_buffer();
void push_buffer(int data);
int pop_buffer();
bool isempty_buffer();

int arr[MAX_SIZE];
static int push;
static int pop;

int init_buffer() {
    push = -1;
    pop = -1;
    memset(arr, 0, sizeof(arr));
    return 1;
}

void push_buffer(int data) {
    if (push == -1 && pop == -1) {
        push++;
        pop++;
        arr[push] = data;
    } else if ((push + 1) % MAX_SIZE == pop) {
        printf("Buffer is full\n");
    } else {
        push++;
        push = push % MAX_SIZE;
        arr[push] = data;
    }
}

int pop_buffer() {
    int data;
    if (isempty_buffer()) {
        return 0;
    } else if (push == pop) {
        data = arr[pop];
        push = -1;
        pop = -1;
        return data;
    } else {
        data = arr[pop];
        arr[pop] = 0;
        pop++;
        pop = pop % MAX_SIZE;
        return data;
    }
}

bool isempty_buffer() {
    if (push == -1 && pop == -1) {
        printf("Buffer is empty\n");
        return true;
    } else {
        return false;
    }
}

int main(void) {
    int rc;
    rc = init_buffer();
    push_buffer(10);
    push_buffer(9);
    printf(" Data removed is %d\n", pop_buffer());
    printf(" Data removed is %d\n", pop_buffer());
    printf(" Data removed is %d\n", pop_buffer());
}

