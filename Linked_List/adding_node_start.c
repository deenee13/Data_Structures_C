#include <stdio.h>
#include <stdlib.h>


struct node{
  int data;
 struct node* next;
};


// Global Declaration 
struct node* head;

// Function Declaration 
void insert(int x);
void print();

// Function to insert node in the beginning of the linked list 
void insert (int x)
{
  struct node* temp = (struct node*) malloc(sizeof(struct node));
  temp->data = x;
  temp->next = head;
  head = temp;
}

// Function to print the linked list
void print()
{
  struct node *temp = head;
  printf("List is:");
  while (temp != NULL)
  {
    printf("%d", temp->data);
    temp = temp->next;
  }
  printf("\n");

} 

int main()
{
  int n;
  int x;
  int i;
  head = NULL; // Empty list  
  printf("How many numbers\n");
  scanf("%d",&n);

  for( i=0; i<n; i++)
  {
    printf("Enter the number you want to insert in the list\n");
    scanf("%d", &x);
    insert(x);
    print();
  }
}
