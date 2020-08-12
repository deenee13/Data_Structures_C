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


/**
 * As node over here don't start from 0 Hence need to build logic to get it
 * done**/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int visited[9];


// Function Declaration 
struct node** read_graph();
struct node** insert_node(int vi, int vj, struct node** head);
void dfs(int i, struct node** head);
void print(struct node*head);




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






struct node** read_graph()
{
    // Graph Variable 
    int node;
    int edge;

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

    // Initializing the array of Pointer's to NULL
    // For Logic purpose
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
        printf("In to the for loop of insert node\n");
    }
    return(temp);
}

struct node** insert_node(int vi, int vj, struct node** head)
{
    printf("Into the Insert node function\n");
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

int main()
{
    struct node** head;
    head = read_graph();
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
    dfs(6,head);
    
    ////print(*(head + 8));
}
