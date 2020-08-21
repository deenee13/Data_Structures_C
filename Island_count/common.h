#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


struct node{
    int data;
    struct node* next;
};

//int visited[9];



/** Function Declaration **/
// Functions for Graph Implementation
struct node** read_graph();
struct node** insert_node(int vi, int vj, struct node** head);
void dfs(int i, struct node** head, int* visited);
void bfs(int i, struct node** head, int* visited);
void print(struct node*head);
void free_linkedlist(struct node** head, int node);
void scale_down(int* link, int edge);
