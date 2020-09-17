#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define INT_MIN INT32_MIN  // Minimum value of INT
#define INT_MAX INT32_MAX  // Maximum value of INT





struct bstnode{
    int data;
    struct bstnode* left;
    struct bstnode* right;
};

/* Function Declaration */

// Function to insert data in tree
struct bstnode* insert(int data, struct bstnode* root);

// Function to create new node in tree
struct bstnode* new_node(int data);

// Function to search particular data in tree
bool  search(struct bstnode* root, int data);

// Function to find minimun value in the tree
struct bstnode* find_min(struct bstnode* root);

// Function to find maximum value in the tree
int find_max(struct bstnode* root);

// Function to find the height of the tree
int find_height(struct bstnode* root);

// to find the maximum value in the tree
int max(int a, int b);

// Function to traverse binary tree level wise
void level_order_traversal(struct bstnode* root);

// Function to traverse binary tree preorder wise
void pre_order_traversal(struct bstnode* root);

// Function to traverse binary tree preorder wise
void in_order_traversal(struct bstnode* root);

// Function to traverse binary tree preorder wise
void post_order_traversal(struct bstnode* root);

// Function to find out wether binary tree is binary search tree
bool is_binary_search_tree(struct bstnode* root);

// Function to find if values in Left BST is lesser than the value passed
bool is_subtree_lesser(struct bstnode* root, int data);

// Function to find if values in Right BST is Greater than the value passed
bool is_subtree_greater(struct bstnode* root, int data);

// Another approach to check if the Binary tree is BST
bool is_bst_util(struct bstnode* root, int min_value, int max_value);

// Function to delete the node from the tree
struct bstnode* delete_node(struct bstnode* root, int data);
