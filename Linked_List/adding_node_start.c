#include <stdio.h>
#include <stdlib.h>


struct node{
  int data;
 struct node* next;
};

// Function Declaration 
struct node* insert(int x, struct node *head);
void print(struct node *head);

// Function to insert node in the beginning of the linked list 
struct node* insert (int x, struct node *head)
{
  struct node* temp = (struct node*) malloc(sizeof(struct node));
  temp->data = x;
  temp->next = head;
  head = temp;
  return (head);
}

// Function to print the linked list
void print(struct node *head)
{
  //struct node *temp = head;
  printf("List is:");
  while (head != NULL)
  {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");


} 

int main()
{
  int n;
  int x;
  int i;
  struct node* head = NULL; // Empty List
  printf("How many numbers\n");
  scanf("%d",&n);

  for( i=0; i<n; i++)
  {
    printf("Enter the number you want to insert in the list\n");
    scanf("%d", &x);
    head = insert(x, head);
    print(head);
  }
}
