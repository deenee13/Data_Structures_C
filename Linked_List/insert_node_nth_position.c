// Inserting a node at Nth Position 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
  int data;
 struct node* next;
};

// Function Declaration 
struct node* insert( int data, int position, struct node *head);
void print(struct node *head);



struct node* insert( int data, int position, struct node *head)
{
    struct node* temp1 = (struct node*) malloc(sizeof(struct node));
    temp1->data = data;
    temp1->next = NULL;

    if(position == 1)
    {
        temp1->next = head;
        head = temp1;
        return(head);
    }

    struct node *temp2 = head;

    // this for loop will take you to n-1 location to get the link proper
    // remember it is staritng fromn 0 that is why it is going till n-2 and not n-1 
    // don't get confuse because of that 
    for( int i=0; i<(position - 2); i++)
    {
        temp2 = temp2->next;
    }
    // First save the value of (n-1)th node next field into our newly creted node->next field
    // Then store the address of the newly created node in to the (n-1)th->next field to get the link proper
    temp1->next = temp2->next;
    temp2->next = temp1;  
    return(head);


}

void print(struct node*head)
{
    struct node *temp = head;
    printf("List:");
    while(temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

}


// You could also take values from the user
int main()
{
    struct node *head = NULL;    // empty list
    head = insert(2,1,head);    // list: 2
    head = insert(3,2,head);    // list: 2,3
    head = insert(4,1, head);    // list: 4,2,3
    head = insert(5,2,head);    // list: 4,5,2,3
    print(head);
}