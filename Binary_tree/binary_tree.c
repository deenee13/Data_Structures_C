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

#include "binary_tree.h"



/***************************************************************************************
 *                     Deleting a Node in BST
 * 
 * To Delete a node from Tree we need to fist break the link and then free the memory in Heap
 * 
 * <CASE-1> Deleting a leaf node is easy as you just need to break the link and free memory  
 * <CASE-2> Deleing a node with 1 child in this we simply need to link the parent of the
 * deleted node with the child of the deleted node
 * <CASE-3> Deleting a node with 2 children. In this we need to find approach tu reduce this
 * with the case-1 or case-2.
 * $step-1$ Find min node in the child of right subtree and fill it in with the deleted node
 * hence we will now have 2 node with same value. Thus doing this we have reduced the problem 
 * to Case-2. Hence to delete the duplicate node follow Case-2 
 *  
 * *************************************************************************************/
struct bstnode* delete_node(struct bstnode* root, int data) {
    if (root == NULL) {
        return (root);
    } else if (data < root->data) {
         // recursive approach to find the particular node to delete it
        root->left = delete_node(root->left, data);
    } else if (data > root->data) {
        root->right = delete_node(root->right, data);
    } else {
        // Got the node to delete
        // Case-1
        if (root->left == NULL && root->right == NULL) {
            // Address of the node we want to delete
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            // Case-2
            // Storing the address of the parent into the temp node
            struct bstnode* temp = root;

            // Updating the address of the parent node with
            // the the address of the right node as to delete it
            root = root->right;
            // Free the previously parent node in memory
            free(temp);
            // return the updated node
        } else if (root->right == NULL) {
            // Storing the address of the parent into the temp node
            struct bstnode* temp = root;

            // Updating the address of the parent node
            // with the the address of the right node as to delete it
            root = root->left;
            // Free the previously parent node in memory
            free(temp);
            // return the updated node
        } else {
            struct bstnode* temp = find_min(root->right);
            printf("Data %d:\n", temp->data);
            root->data = temp->data;
            root->right = delete_node(root->right, root->data);
        }
    }
    return(root);
}
/***************************************************************************************
 *                      Different approach to test if binary tree is BST
 * 
 * As the previous function was calling recursively(depending upon the number of node in function) 
 * to two functions. Which was very expensive. Thus over here we are seeing the upper and lower 
 * bound value to reduce recrusiveness 
 *  
 * *************************************************************************************/
bool is_bst_util(struct bstnode* root, int min_value, int max_value) {
    // Base condition to Exit the function
    if (root == NULL) {
        return true;
    }

    if ( root->data > min_value && root->data < max_value &&
        is_bst_util(root->left, min_value, root->data) &&
        is_bst_util(root->right, root->data, max_value)) {
        return true;
    } else {
        return false;
    }
}





bool is_subtree_greater(struct bstnode* root, int data) {
    if (root == NULL) {
        return true;
    }
    if (root->data > data && is_subtree_greater(root->left, data) &&
        is_subtree_greater(root->right, data)) {
        return true;
    } else {
        return false;
    }
}


bool is_subtree_lesser(struct bstnode* root, int data) {
    if (root == NULL) {
        return true;
    }
    if (root->data <= data && is_subtree_lesser(root->left, data) &&
        is_subtree_lesser(root->right, data)) {
        return true;
    } else {
        return false;
    }
}


/* **************************************************************************************
 *                     Find if Binary Tree is Binary Search Tree
 * 
 * Assuming Binary Tree we are first passing the Address of the left node to a function
 * to check if it is lesser than the actual root node and same must be true for the 
 * respective further tree hence we are repeating the same process by again calling 
 * is_binary_search_tree function for left node. Same process is repeat for the right node
 * 
 *             
 * Another way to implemnt it is to find the maximum value in the left subtree and compare 
 * it with the value at the root node if it is lesser then we are good and in similar 
 * fashion finding minimum value in the right subtreee and compare it with root node value 
 * if it is greater then we are good else reeturn false   
 * 
 * 
 *  <Drawback> In this function we are calling two function in recursion which is very expensive 
 *  as for each node we are looking for all the subnode in that tree which is very expensive
 *  Hence need to find the alternative method        
 *  
 * *************************************************************************************/
bool is_binary_search_tree(struct bstnode* root) {
    // Base condition to Exit the function
    if (root == NULL) {
        return true;
    }

    if ( is_subtree_lesser(root->left, root->data) &&
        is_subtree_greater(root->right, root->data) &&
        is_binary_search_tree(root->left) &&
        is_binary_search_tree(root->right)) {
        return true;
    } else {
        return false;
    }
    /* Different approach for same problem uncomment to try*/
    // return(is_bst_util(root, INT_MIN, INT_MAX));
}


/***************************************************************************************
 *                      Post-order Traversal
 * 
 *  In this Traversal technique first left subtree is visited and data is printed
 *  then right subtree is visited and its data is printed then root node is visited
 * 
 *                        <LEFT> <RIGHT> <ROOT> 
 *  
 * *************************************************************************************/
void post_order_traversal(struct bstnode* root) {
    if (root == NULL) {
        return;
    }
    post_order_traversal(root->left);
    post_order_traversal(root->right);
    printf("%d ", root->data);
}

/***************************************************************************************
 *                      In-order Traversal(Binary search tree)
 * 
 *  In this Traversal technique first left subtree is visited and data is printed
 *  then root node data is printed then right subtree is visited and its data is printed
 * 
 *                        <LEFT> <ROOT> <RIGHT> 
 *  
 * *************************************************************************************/
void in_order_traversal(struct bstnode* root) {
    if (root == NULL) {
        return;
    }
    in_order_traversal(root->left);
    printf("%d ", root->data);
    in_order_traversal(root->right);
}


/***************************************************************************************
 *                      Pre-order Traversal
 * 
 *  In this Traversal technique first data at root node is visited 
 *  and then left sub tree is visited and then the right subtree
 * 
 *                        <ROOT> <LEFT> <RIGHT> 
 *  
 * *************************************************************************************/
void pre_order_traversal(struct bstnode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);
}

/***************************************************************************************
 *                      Level-Order Traversal
 * 
 *  In this Traversal technique elements which are present at 
 *  the same level are read first from left to right and then
 *  goes to the lower level
 * 
 * It is also call breadth first search algorithm and it works in the same way as BFS of tree
 * *************************************************************************************/
void level_order_traversal(struct bstnode* root) {
    if (root == NULL) {
        return;
    } else {
        /* code */
    }
}

// #define Function_name(arg1, arg2) ((arg1) <some operation> (arg2) ? (condition to execute) : (condition to execute else))
#define MAX(a, b) ( (a) >= (b) ? a : b)


int max(int a, int b) {
    // printf("Value of a in max: %d\n",a);
    // printf("Value of b in max: %d\n",b);
    if (a > b) {
        return(a);
    } else {
        return(b);
    }
}

// Function to find the height of the tree
int find_height(struct bstnode* root) {
    if (root == NULL) {
        return (0);
    }
    /*
    else
    {
        int left_side = find_height(root->left);
        int right_side = find_height(root->right);
        printf("Value of left side:%d\n",left_side);
        printf("Value of right side:%d\n",right_side);
    }
    */
return(( max(find_height(root->left), find_height(root->right)) + 1 ));
}


// Function to find maximum element in the tree
int find_max(struct bstnode* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
    } else if (root->right == NULL) {
        return (root->data);
    }
    // Search in left subtree
    return (find_max(root->right));
}

// Function to find minimun value in the tree
struct bstnode* find_min(struct bstnode* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
    } else if (root->left == NULL) {
        return (root);
    }
    // Search in left subtree
    return (find_min(root->left));
}

// Function to search particular data in Tree
bool  search(struct bstnode* root, int data) {
    if (root == NULL) {
        return false;
    } else if (data == root->data) {
        return true;
    } else if (data <= root->data) {
        return(search(root->left, data));
    } else {
        return(search(root->right, data));
    }
}


// Function to create new node in tree
struct bstnode* new_node(int data) {
    struct bstnode* newnode;
    newnode = (struct bstnode*) malloc(sizeof(struct bstnode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return(newnode);
}


// Function to insert data in tree
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


int main(void) {
    struct bstnode* rootptr = NULL;  // To store address of root node
    struct bstnode* num1 = NULL;
    int num;
    // Inserting element in the tree
    rootptr = insert(15, rootptr);
    rootptr = insert(10, rootptr);
    rootptr = insert(20, rootptr);
    rootptr = insert(8, rootptr);
    rootptr = insert(12, rootptr);
    rootptr = insert(6, rootptr);
    rootptr = insert(11, rootptr);
    rootptr = insert(17, rootptr);
    rootptr = insert(25, rootptr);
    rootptr = insert(16, rootptr);
    rootptr = insert(27, rootptr);

    printf("Enter the number to be searched:");
    scanf("%d", &num);

    // Searching element in the tree
    if (search(rootptr, num) == true) {
        printf("Found\n");
    } else {
        printf("Not found\n");
    }

    // Searching minimum element in the tree
    num1 = find_min(rootptr);
    printf("Minimum element in the tree is %d\n", num1->data);

    // Searching maximum element in the tree
    num = find_max(rootptr);
    printf("Maximum element in the tree is %d\n", num);

    num = find_height(rootptr);
    printf("Height of the tree is %d\n", num);

    printf("Value of the pre-order traversal is:\n");
    pre_order_traversal(rootptr);

    printf("\n");

    printf("Value of the in-order traversal is:\n");
    in_order_traversal(rootptr);

    printf("\n");

    printf("Value of the post-order traversal is:\n");
    post_order_traversal(rootptr);

    printf("\n");

    printf(" To know wether Binary Tree is Binary Search Tree\n");
    bool flag = is_binary_search_tree(rootptr);
    printf("Is binary tree a Binary Search Tree: %d\n", flag);

    rootptr = delete_node(rootptr, 15);

    printf("Enter the number to be searched:");
    scanf("%d", &num);

    // Searching element in the tree
    if (search(rootptr, num) == true) {
        printf("Found\n");
    } else {
        printf("Not found\n");
    }
}
