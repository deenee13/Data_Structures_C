/**
 *          1----2-----3    6   8
 *          |    |          |
 *          4----5          7
 *
 * islandcounts(): Takes three arguments that describes the graph.
 *                  int node : The number of nodes. Which are numbered consecutively from 1 to N
 *                  int edge : The number of edges.
 *                  int *e : An integer array that contains pairs of elements that say which pairs of nodes
 *                  connected together
 *
 * for the above example array e looks like e = {2,3,1,2,1,4,2,5,4,5,6,7}
 *
 * The first pair of elements is 2,3 which means that node 2 and 3 are connected together and so on. Hence we
 * can say in total there are total 2*(edge) elements in the array.
 *
 * The goal of the function is to return the number of islands in the graph. An island is a group of nodes that are
 * connected only to themselves and not to any other nodes in the graph.
 * **/



//<TODO: To fix this error>
/**
 * As node over here don't start from 0 Hence need to build logic to get it
 * done**/

#include <stdio.h>
#include <stdlib.h>
#include "common.h"


// Function to free the dyamically allocated memory 
void free_linkedlist(struct node** head, int edge)
{
    struct node* p;
    for(int i=0; i<2*edge; i++)
    {
        p = *(head + i);
        while(p != NULL)
        {
            free(p);
            p = p->next;
        }
    }
    printf("Linked list memory is deallocated\n ");
}


// Function to Traverse the Graph in Breadth Fisrst Search Algorithm
void bfs(int i, struct node** head)
{
    printf("In to the BFS function\n");
    struct node** temp = head;
    struct node*p;

    // Insert the element in the Queue
    enqueue(i);
    visited[i] = 1;
    while(!isempty())
    {
        ////printf("Into while loop\n");
        i = peek();
        printf("%d\n",i);
        dequeue();

        // Pass the address of the specific head to p
        p = *(temp + i);

        // Run the loop until that specific list reaches NULL
        while(p != NULL)
        {
            if(visited[p->data] == 0)
            {
                // Put the elements of the into the queue
                enqueue(p->data);

                visited[p->data] = 1;
            }
            // Move forward in the list
            p = p->next;
        }

    }

}



// function to traverse the graph in the Depth First Search Algorithm
void dfs(int i, struct node** head)
{
    struct node** temp = head;
    struct node* p;
    printf("\n%d",i);
    p = *(temp + i);
    visited[i] = 1;
    while(p != NULL)
    {
        i = p->data;
        if(visited[i] == 0)
        {
            dfs(i,temp);
        }
        p = p->next;
    }
}


// function to read the graph and to print the total number of island
struct node** read_graph()
{
    // Graph Variable
    int node;
    int edge;
    
    // Variables used to display the island count
    int num;
    int count;

    // Pointer to an array which will store the head of the linked list
    struct node** temp;
    temp = (struct node**) malloc((node + 1)*sizeof(struct node*));

    // To take the number of nodes
    printf("Number of nodes in the graph are:");
    scanf("%d",&node);

    //  To take the number of edges
    printf("Number of edges in the graph are:");
    scanf("%d",&edge);

    // Array to store the link of the nodes
    int links[2*edge];
    printf("Enter the nodes which are connected via edges:");
    for (int i = 0; i < (2*edge); i++)
    {
        scanf("%d",&links[i]);
    }

    // Initializing the array of Pointer's to NULL
    for(int j=0; j < node; j++ )
    {
        *(temp + j) = NULL;
        //printf("In to the for loop of aaray of pointers\n");
    }


    // Initializing the array of Visited to Null
    for(int j=0; j < 9; j++ )
    {
        visited[j] = 0;
        //printf("In to the for loop of visited array\n");
    }

    // For loop used to connect all the links to the particular node using linked list
    for(int i=0; i < (2*edge); i = i+2)
    {
        ////printf("Value of i is %d\n",i);
        ////printf("Value of the links is %d and %d\n",links[i],links[i+1]);
        temp = insert_node(links[i], links[i+1], temp);
        temp = insert_node(links[i+1], links[i], temp);
        ////printf("In to the for loop of insert node\n");
    }

    // Going through the Link array to traverse the list
    // Change the logic again to 0 once solved the 0 error
    for(int i=1; i <= node; i++)
    {
        if(visited[i] == 0)
        {
            printf("debug1\n");
            bfs(i,temp);
            count++;
        }
    }
    printf("Total number of the Islands are:%d\n",count);


    // Logic to free the Dynamic memory which is allocated via linked list 
    printf("Do you want to free memory:");
    scanf("%d",&num);
    if(num == 1)
    {
        free_linkedlist(temp, edge);
    }
    
    return(temp);
}

struct node** insert_node(int vi, int vj, struct node** head)
{
    ////printf("Into the Insert node function\n");
    struct node* p = NULL;
    struct node* q = NULL;

    q = (struct node*) malloc(sizeof(struct node*));
    q->data = vj;
    q->next = NULL;

    // If in the array of Heads that location is null simply store the address of new node in it
    if (*(head + vi) == NULL)
    {
        *(head + vi) = q;
    }

    // If it is not null then store the head in some temporary variable then goto the end
    // of that list and then store the address of the new node in it
    else
    {
        p = *(head + vi);
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = q;
    }
    return(head);
}

// Function to Print the linked list for the debug purpose
void print(struct node* head)
{
    struct node *temp = head;
    printf("List:");
    if(temp == NULL)
    {
        printf("Locatin is NULL\n");
    }
    while(temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


/* Function  for Queue*/

void dequeue()
{
    // It is created to delete the memory from heap
    struct node* temp = front;
    if(front == NULL)
    {
        return;
    }
    if(front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
    }

    free(temp);
}

void enqueue(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node*));
    temp->data = x;
    temp->next = NULL;

    if(front == NULL && rear == NULL)
    {
        rear = temp;
        front = temp;
        return;
    }

    // Try to implement this logic on paper and it will be more clear
    rear->next = temp;
    rear = temp;
}

int isempty(void)
{
    if( front == NULL && rear == NULL)
    {
        return(1);
    }
    else
    {
        return(0);
    }

}

int peek()
{
    // Check for the empty Queue
    if(front != NULL)
    {
        return(front->data);
    }
    else
    {
        printf("Queue is empty exiting the code\n");
        exit(EXIT_FAILURE);
    }
}


int main()
{
    struct node** head;
    head = read_graph();

    // For debug Purpose
    /*
    print(*(head + 1));
    print(*(head + 2));
    print(*(head + 3));
    print(*(head + 4));
    print(*(head + 5));
    print(*(head + 6));
    print(*(head + 7));

    if(*(head + 0) == NULL)
    {
        printf("It is NULL\n");
    }

    if(*(head + 8) == NULL)
    {
        printf("It is NULL\n");
    }
    else
    {
        print(*(head + 8));
    }
    //dfs(6,head);
    bfs(1,head);
    */
}