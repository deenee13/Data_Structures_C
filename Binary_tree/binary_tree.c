/* Implementation of Binary Search Tree*/

/* A binary search tree in which for each node
values of all the nodes in left subtree is lesser 
or equal and all the nodes in right subtree is greater
This phenomena must be true for all the nodes*/


/** In BST We treat the root of the BST same as the Head in Linked list**/

/*** I have Implemented it using recursion as it is easy to implement it
 * we can implement it without recursion but it will need a lot temporary
 * variables and loops to get the same logic
 * ***/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct bstnode{
    int data;
    struct bstnode* left;
    struct bstnode* right;
};

// Function Declaration
struct bstnode* insert(int data, struct bstnode* root); // Function to insert data in tree
struct bstnode* new_node(int data); // Function to create new node in tree
bool  search(struct bstnode* root, int data); // Function to search particular data in tree
int find_min(struct bstnode* root); // Function to find minimun value in the tree
int find_max(struct bstnode* root); // Function to find maximum value in the tree
int find_height(struct bstnode* root);


int find_height(struct bstnode* root)
{
    if(root == NULL){
        return (-1);
    }
    return((max(find_height(root->left),find_height(root->right))) + 1 );
}
// Function to find maximum lement in the  tree
int find_max(struct bstnode* root)
{    
    if(root == NULL)
    {
        printf("Tree is empty\n");
    }
    else if (root->right == NULL)
    {
        return (root->data);
    }

    // Search in left subtree
    return (find_max(root->right));

}

// Function to find minimun value in the tree
int find_min(struct bstnode* root)
{
    if(root == NULL)
    {
        printf("Tree is empty\n");
    }
    else if (root->left == NULL)
    {
        return (root->data);
    }

    // Search in left subtree
    return (find_min(root->left));
}

// Function to search particular data in Tree
bool  search(struct bstnode* root, int data)
{
    if(root == NULL)
    {
        return false;
    }
    else if(root->data == data)
    {
        return true;
    }
    else if (data <= root->data)
    {
        return(search(root->left,data));
    }
    else 
    {
        return(search(root->right,data));
    }
}


// Function to create new node in tree
struct bstnode* new_node(int data)
{
    struct bstnode* newnode = (struct bstnode*) malloc(sizeof(struct bstnode));
    newnode->data = data;
    newnode->left = NULL;  
    newnode->right = NULL;
    return(newnode);
}


// Function to insert data in tree
struct bstnode* insert(int data, struct bstnode* root)
{
   if(root == NULL)
   {
        root = new_node(data); 
   }
   else if(data <= root->data)
   {
       root->left = insert(data, root->left);
   }
   else
   {
       root->right = insert(data, root->right);
   }

   return root;
}


int main()
{
    struct bstnode* rootptr = NULL;  // To store address of root node
    int num;

    // Inserting element in the tree
    rootptr = insert(15,rootptr);
    rootptr = insert(10,rootptr);
    rootptr = insert(20,rootptr);
    rootptr = insert(8,rootptr);
    rootptr = insert(12,rootptr);
    rootptr = insert(17,rootptr);
    rootptr = insert(25,rootptr);

    printf("Enter the number to be searched:");
    scanf("%d",&num);

    // Searching element in the tree
    if(search(rootptr,num) == true)
    {
        printf("Found\n");
    }
    else
    {
        printf("Not found\n");
    }

    // Searching minimum element in the tree
    num = find_min(rootptr);
    printf("Minimum element in the tree is %d\n", num);

    // Searching maximum element in the tree
    num = find_max(rootptr);
    printf("Maximum element in the tree is %d\n", num);

    num = find_height(rootptr);
    printf("Height of the tree is %d\n", num);
}