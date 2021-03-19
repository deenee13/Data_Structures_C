#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "binary_tree.h"

/**************** Queue Starts ********************/
struct node {
    struct bstnode* data;
    struct node* next;
};

void enqueue(struct bstnode* data);
void dequeue();
struct bstnode* peek();
bool isempty();

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(struct bstnode* data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = newnode;
        rear = newnode;
        return;
    }

    rear->next = newnode;
    rear = newnode;
}

void dequeue() {
    struct node* temp = front;

    if  (front == NULL) {
        return;
    }

    if (front == rear) {
        front = NULL;
        rear = NULL;
        return;
    } else {
        front = front->next;
    }
    
    free(temp);
}

struct bstnode* peek() {

    if (front != NULL) {
        return front->data;
    } else {
        printf("Queue is empty\n");
    }
}

bool isempty() {
    if (front != NULL && rear != NULL) {
        return false;
    } else {
        return true;
    }
}
/**************** Queue Ends ********************/

// Function to create new node in tree
struct bstnode* new_node(int data) {
    struct bstnode* newnode;
    newnode = (struct bstnode*) malloc(sizeof(struct bstnode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return(newnode);
}

// Function to Insert node
struct bstnode* insert(int data, struct bstnode* root) {
if (root == NULL) {
    root = new_node(data);
} else if (data <= root->data) {
    root->left = insert(data, root->left);
    } else {
    root->right = insert(data, root->right);
}
return root;
}

// Function to print left view of the tree
void leftviewutil(struct bstnode* root, int level, int* max_level) {

    if (root == NULL) {
        return;
    }

    if (*max_level < level) {
        printf("%d\n", root->data);
        *max_level = level;
    }
    leftviewutil(root->left, level + 1, max_level);
    leftviewutil(root->right, level + 1, max_level);
}
// Function to print left view of the tree
void leftview_recursion(struct bstnode* root) {
    int max_level = 0;
    leftviewutil(root, 1, &max_level);
}

// function to print right view of the tree
void rightviewutil(struct bstnode* root, int level, int* max_level) {

    if (root == NULL) {
        return;
    }

    if (*max_level < level) {
        printf("%d\n", root->data);
        *max_level = level;
    }
    rightviewutil(root->right, level + 1, max_level);
    rightviewutil(root->left, level + 1, max_level);
}

// Function to print right view of the tree
void rightview_recursion(struct bstnode* root) {
    int max_level = 0;
    rightviewutil(root, 1, &max_level);
}

// Level Order Traversal
void level_order_traversal(struct bstnode* root) {
    struct bstnode* temp = NULL;
    if (root == NULL) {
        return;
    } else {
        enqueue(root);
        while (!isempty()) {
            temp = peek();
            if (temp->left != NULL) enqueue(temp->left);
            if (temp->right != NULL) enqueue(temp->right);
            dequeue();
            printf("%d\n", temp->data);
        }
    }
}

struct bstnode* convert_utill(int* arr, int low, int high) {

    // base case donot forget
    if (low > high) {
        return NULL;
    }
    struct bstnode* root = NULL;
    int mid = (low + high)/2;

    root = new_node(arr[mid]);
    root->data = arr[mid];
    root->left  = convert_utill(arr, low, mid - 1);
    root->right = convert_utill(arr, mid + 1, high);

    return root;
}

// Convert array into Tree
struct bstnode* convert_tree(int* arr, int size) {

    // Construct a balanced bianry tree
    struct bstnode* rootptr = NULL;
    rootptr = convert_utill(arr, 0, size-1); 

    return rootptr;
}

int main(void) {
    struct bstnode* rootptr = NULL;
    int arr[] = {1,3,4,5,6,7,9,12,13,15,16,17,19};
    int size = sizeof(arr)/sizeof(arr[0]);
    // Inserting elements in the tree
    rootptr = insert(12, rootptr);
    rootptr = insert(5, rootptr);
    rootptr = insert(15, rootptr);
    rootptr = insert(3, rootptr);
    rootptr = insert(7, rootptr);
    rootptr = insert(13, rootptr);
    rootptr = insert(17, rootptr);
    rootptr = insert(1, rootptr);
    rootptr = insert(4, rootptr);
    rootptr = insert(6, rootptr);
    rootptr = insert(9, rootptr);
    rootptr = insert(16, rootptr);
    rootptr = insert(19, rootptr);

    // Printing left view of the tree
    printf("******* Print left view *********\n");
    leftview_recursion(rootptr);

    // Printing left view of the tree
    printf("******* Print right view *********\n");
    rightview_recursion(rootptr);

    // Level order traversal in tree
    printf("******* Pre Level Order Traversal *********\n");
    level_order_traversal(rootptr);

    // convert array into binary tree
    // NOTE: Considering user has passed sorted array
    // If not sort the array first
    rootptr = convert_tree(arr, size);

    // Level order traversal in tree
    printf("******* Post Level Order Traversal *********\n");
    level_order_traversal(rootptr);
}