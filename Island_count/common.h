#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


struct node{
    int data;
    struct node* next;
};

int visited[9];
struct node* front = NULL; // Flag for Queue Implementation
struct node* rear = NULL; // Flag for Queue Implementation


/** Function Declaration **/
// Functions for Graph Implementation
struct node** read_graph();
struct node** insert_node(int vi, int vj, struct node** head);
void dfs(int i, struct node** head);
void bfs(int i, struct node** head);
void print(struct node*head);
void free_linkedlist(struct node** head, int edge);
// Functions for Queue Implementation
void enqueue(int x);     // To add element from the queue
void dequeue();          // To remove element from the queue
int isempty(void);           // Function to check whether queue is empty or not
int peek();