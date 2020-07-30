#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node{
  int data;
 struct node* next;
};

// Function Declaration 
struct node* insert(int x, struct node *head);
void print(struct node *head);
bool hascycle(struct node *head); 

// Function to insert node in the beginning of the linked list 
struct node* insert (int x, struct node *head)
{
  struct node* temp = (struct node*) malloc(sizeof(struct node));
  temp->data = x;
  temp->next = head;
  head = temp;
  return (head);
}

// Function to see whether there is loop in linked list 
bool hascycle(struct node *head)
{
  
  struct node *slow;
  struct node *fast;

  if(head == NULL || head->next == NULL)
  {
  
    printf("False");
    return false;
  }
  
  slow = head;
  fast = head->next;

  while( slow != fast)
  {
    printf("In while loop\n");
    if(fast == NULL || fast->next == NULL)
    {
      printf("False");
      return false;

    }
    slow = slow->next;
    fast = fast->next->next;
  }
  printf("True");
  return true;
}

// Function to print the linked list
void print(struct node *head)
{

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
  hascycle(head);
  //printf("Result is %s", result);
}
