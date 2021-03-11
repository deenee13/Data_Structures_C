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
struct node* delete_smallest(struct node *head);
struct node* copy_linkedlist(struct node* head);

struct node* copy_linkedlist(struct node* head) {
  unsigned int node = 0;
  if (head == NULL) {
    return head;
  }
  struct node* prev = NULL;
  struct node* new_head = NULL;
  while (head != NULL) {

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = head->data;
    newnode->next = NULL;

    if (node == 0) {
      new_head = newnode;
    } else {

      prev->next = newnode;
    }
    prev = newnode;
    node++;
    head = head->next;
  }
  return new_head;
}

// Function to insert node in the beginning of the linked list
struct node* insert(int x, struct node *head) {
  struct node* temp = (struct node*) malloc(sizeof(struct node));
  temp->data = x;
  temp->next = head;
  head = temp;
  return head;
}

// Function to see whether there is loop in linked list
bool hascycle(struct node *head) {
  struct node *slow;
  struct node *fast;

  if (head == NULL || head->next == NULL) {
    printf("False");
    return false;
  }
  slow = head;
  fast = head->next;

  while (slow != fast) {
    //// printf("In while loop\n");
    if (fast == NULL || fast->next == NULL) {
      printf("False\n");
      return false;
    }
    slow = slow->next;
    fast = fast->next->next;
  }
  printf("True\n");
  return true;
}

struct node* delete_smallest(struct node *head) {

  struct node *temp = head;
  struct node *delete;
  int smallest_value = 0;
  unsigned int position = 1;
  unsigned int count = 1;

  smallest_value = head->data;
  while (temp != NULL) {
    if (smallest_value > temp->data) {
      smallest_value = temp->data;
      position = count;
    }
    count++;

    temp = temp->next;
  }

  printf("smallest_Value = %d and position = %d\n", smallest_value, position);

  if (position == 1) {

    delete = head;
    head = head->next;
    free(delete);
  } else {

    struct node *prev = head;
    for (int i = 0; i < (position - 2); i++) {
      prev = prev->next;
    }
    struct node *current = prev->next;
    prev->next = current->next;
    free(current);

  }
  return head;
}

// Function to print the linked list
void print(struct node *head) {
  printf("List is:");
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {

  int n;
  int x;
  int i;
  struct node* head = NULL;  //  Empty List
  printf("How many numbers\n");
  scanf("%d", &n);

  for (i=0; i < n; i++) {
    printf("Enter the number you want to insert in the list\n");
    scanf("%d", &x);
    head = insert(x, head);
    print(head);
  }
  hascycle(head);
  head = delete_smallest(head);
  print(head);
  // printf("Result is %s", result);

  head = copy_linkedlist(head);
  printf("Copied linked ");
  print(head);

  printf("Size of struct %lu\n", sizeof(struct node));
}
