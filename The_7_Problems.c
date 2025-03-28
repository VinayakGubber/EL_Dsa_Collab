// Problem: Find pairs in a doubly linked list with a given sum
//
// Optimal Approach: Uses two pointers (one from the start and one from the end) to efficiently
// find pairs that sum up to the given target. The approach reduces unnecessary iterations by
// moving the pointers inward based on the sum comparison.

#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in a doubly linked list
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Definition of a Doubly Linked List
typedef struct DoublyLinkedList
{
    Node *head;
    Node *tail;
} DoublyLinkedList;

// Function to create a new node with given data
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to add a node at the end of the doubly linked list
void addNode(DoublyLinkedList *dll, int data)
{
    Node *newNode = createNode(data);

    // If list is empty, initialize head and tail
    if (dll->head == NULL)
    {
        dll->head = dll->tail = newNode;
    }
    else
    {
        dll->tail->next = newNode;
        newNode->prev = dll->tail;
        dll->tail = newNode;
    }
}

// Function to find and print all pairs with a given sum
void findPairsWithSum(DoublyLinkedList *dll, int target)
{
    // If list is empty or has only one node, no pairs exist
    if (dll->head == NULL || dll->tail == NULL)
    {
        printf("The list is empty or has only one element.\n");
        return;
    }

    Node *left = dll->head;
    Node *right = dll->tail;
    int found = 0;

    printf("Pairs with sum %d:\n", target);

    // Using two-pointer technique to find pairs
    while (left != NULL && right != NULL && left != right && left->next != right)
    {
        int sum = left->data + right->data;

        if (sum == target)
        {
            printf("(%d, %d)\n", left->data, right->data);
            found = 1;
            left = left->next;
            right = right->prev;
        }
        else if (sum < target)
        {
            left = left->next; // Move left pointer forward
        }
        else
        {
            right = right->prev; // Move right pointer backward
        }
    }

    if (!found)
    {
        printf("No pairs found.\n");
    }
}

int main()
{
    // Initialize an empty doubly linked list
    DoublyLinkedList dll;
    dll.head = NULL;
    dll.tail = NULL;

    // Insert elements into the list
    addNode(&dll, 1);
    addNode(&dll, 2);
    addNode(&dll, 4);
    addNode(&dll, 5);
    addNode(&dll, 6);
    addNode(&dll, 8);
    addNode(&dll, 9);

    int target = 10;

    // Find pairs that sum up to the target value
    findPairsWithSum(&dll, target);

    // Free allocated memory
    Node *temp;
    while (dll.head != NULL)
    {
        temp = dll.head;
        dll.head = dll.head->next;
        free(temp);
    }

    return 0;
}

// End of problem

// Problem: Inorder Traversal of a Binary Tree
//
// Optimal Approach: Uses recursion to traverse the tree in an inorder fashion (Left, Root, Right).
// This method ensures that elements are visited in sorted order for a Binary Search Tree (BST).

#include <stdio.h>
#include <stdlib.h>

// Definition of a Tree Node
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new tree node with given value
TreeNode *createNode(int value)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to perform inorder traversal (Left, Root, Right)
void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main()
{
    // Constructing the Binary Tree
    TreeNode *root = createNode(3);
    root->left = createNode(2);
    root->right = createNode(4);
    root->left->left = createNode(1);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(8);

    // Performing inorder traversal
    inorder(root); // Output: 1 2 5 3 6 4 8

    return 0;
}

// End of problem

< -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --->

// Maximum and minimum of an array using minimum number of comparisons

// Code for Optimal Approach (Uses comparing in pairs) - The idea is that when n is odd then initialize min and max as the first element. If n is even then initialize min and max as minimum and maximum of the first two elements respectively. For the rest of the elements, pick them in pairs and compare their maximum and minimum with max and min respectively.
#include <stdio.h>
                                                                                                                void
                                                                                                                getMinMax(int arr[], int n, int *min, int *max)
{
    int i = 0;

    // Initialize min and max based on whether n is even or odd
    if (n % 2 == 0)
    {
        if (arr[0] > arr[1])
        {
            *max = arr[0];
            *min = arr[1];
        }
        else
        {
            *min = arr[0];
            *max = arr[1];
        }
        i = 2; // Start loop from index 2
    }
    else
    {
        *min = *max = arr[0];
        i = 1; // Start loop from index 1
    }

    // Process elements in pairs
    while (i < n - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            if (arr[i] > *max)
                *max = arr[i];
            if (arr[i + 1] < *min)
                *min = arr[i + 1];
        }
        else
        {
            if (arr[i + 1] > *max)
                *max = arr[i + 1];
            if (arr[i] < *min)
                *min = arr[i];
        }
        i += 2; // Increment by 2 as we process pairs
    }
}

int main()
{
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    getMinMax(arr, n, &min, &max);

    // Print results
    printf("Minimum element is %d\n", min);
    printf("Maximum element is %d\n", max);

    return 0;
}

// End of problem

// Problem: Find pairs with a given sum in a Doubly Linked List
// Optimal Approach: Using two-pointer technique
// Description: Traverse the list with two pointers, one from the head and one from the tail,
// moving them towards each other based on the sum comparison to efficiently find the pairs.

#include <stdio.h>
#include <stdlib.h>

// Structure for a Doubly Linked List Node
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Structure for Doubly Linked List
typedef struct DoublyLinkedList
{
    Node *head;
    Node *tail;
} DoublyLinkedList;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to add a node to the end of the doubly linked list
void addNode(DoublyLinkedList *dll, int data)
{
    Node *newNode = createNode(data);
    if (dll->head == NULL)
    {
        dll->head = dll->tail = newNode;
    }
    else
    {
        dll->tail->next = newNode;
        newNode->prev = dll->tail;
        dll->tail = newNode;
    }
}

// Function to find pairs with a given sum in a doubly linked list
void findPairsWithSum(DoublyLinkedList *dll, int target)
{
    if (dll->head == NULL || dll->tail == NULL)
    {
        printf("The list is empty or has only one element.\n");
        return;
    }

    Node *left = dll->head;
    Node *right = dll->tail;
    printf("Pairs with sum %d:\n", target);
    int found = 0;

    while (left != NULL && right != NULL && left != right && left->next != right)
    {
        int sum = left->data + right->data;
        if (sum == target)
        {
            printf("(%d, %d)\n", left->data, right->data);
            found = 1;
            left = left->next;
            right = right->prev;
        }
        else if (sum < target)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }

    if (!found)
    {
        printf("No pairs found.\n");
    }
}

// Driver Code
int main()
{
    DoublyLinkedList dll;
    dll.head = NULL;
    dll.tail = NULL;

    // Adding elements to the doubly linked list
    addNode(&dll, 1);
    addNode(&dll, 2);
    addNode(&dll, 4);
    addNode(&dll, 5);
    addNode(&dll, 6);
    addNode(&dll, 8);
    addNode(&dll, 9);

    int target = 10;

    // Finding pairs with the given sum
    findPairsWithSum(&dll, target);

    // Free allocated memory
    Node *temp;
    while (dll.head != NULL)
    {
        temp = dll.head;
        dll.head = dll.head->next;
        free(temp);
    }

    return 0;
}

// End of program

// Problem: Inorder Traversal of a Binary Tree
// Optimal Approach: Recursive Inorder Traversal
// Description: Recursively visit the left subtree, print the current node, then visit the right subtree.

#include <stdio.h>
#include <stdlib.h>

// Structure for a Binary Tree Node
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new node
TreeNode *createNode(int value)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to perform inorder traversal
void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Driver Code
int main()
{
    // Creating a sample binary tree
    TreeNode *root = createNode(3);
    root->left = createNode(2);
    root->right = createNode(4);
    root->left->left = createNode(1);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(8);

    // Performing inorder traversal
    inorder(root); // Expected Output: 1 2 5 3 6 4 8

    return 0;
}

// End of program




//To return the number of nodes in the BST whose value lie in the given range.
//Optimal Approach:
//Use BST properties to avoid unnecessary traversal: 
//•	If root->data < l, search only in the right subtree.
//•	If root->data > h, search only in the left subtree.
//•	If root->data is in range [l, h], count it and explore both subtrees

#include <stdio.h>
#include <stdlib.h>
// Structure of a BST node
typedef struct Node {
int data;
struct Node *left, *right;
} Node;
// Function to create a new node
Node* newNode(int data) {
Node* temp = (Node*)malloc(sizeof(Node));
temp->data = data;
temp->left = temp->right = NULL;
return temp;
}
// Optimized function to count nodes in range
int countNodesInRangeOptimized(Node* root, int l, int h) {
if (root == NULL)
return 0;
// If the node's value is in range, count it and explore both sides
if (root->data >= l && root->data <= h)
return 1 + countNodesInRangeOptimized(root->left, l, h) + countNodesInRangeOptimized(root->right, l, h);
// If the node's value is smaller than l, go right
if (root->data < l)
return countNodesInRangeOptimized(root->right, l, h);
// If the node's value is greater than h, go left
return countNodesInRangeOptimized(root->left, l, h);
}
// Insert a node in BST
Node* insert(Node* root, int data) {
if (root == NULL)
return newNode(data);
if (data < root->data)
root->left = insert(root->left, data);
else
root->right = insert(root->right, data);
return root;
}
// Driver Code
int main() {
Node* root = NULL;
root = insert(root, 10);
root = insert(root, 5);
root = insert(root, 1);
root = insert(root, 8);
root = insert(root, 15);
root = insert(root, 12);
root = insert(root, 20);
int l = 5, h = 15;
printf("Optimized Approach: Nodes in range [%d, %d] = %d\n", l, h, countNodesInRangeOptimized(root, l, h));
return 0;
}
//End of the program.
