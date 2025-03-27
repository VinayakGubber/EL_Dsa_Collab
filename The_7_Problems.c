// Maximum and minimum of an array using minimum number of comparisons

// Code for Optimal Approach (Uses comparing in pairs) - The idea is that when n is odd then initialize min and max as the first element. If n is even then initialize min and max as minimum and maximum of the first two elements respectively. For the rest of the elements, pick them in pairs and compare their maximum and minimum with max and min respectively.
#include <stdio.h>
void getMinMax(int arr[], int n, int *min, int *max)
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
<<<<<<< HEAD

//Find out the second most repeated (or frequent) string in the given sequence.
#include <stdio.h>
#include <string.h>
#define MAX 100
// Function to sort an array of strings (using Bubble Sort for simplicity)
void sortStrings(char arr[][MAX], int n) 
{
    char temp[MAX];
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (strcmp(arr[i], arr[j]) > 0) 
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}
// Function to find the second most repeated string
void findSecondMostRepeated(char arr[][MAX], int n) 
{
sortStrings(arr, n);

    int max1 = 0, max2 = 0, count = 1;
    char mostFrequent[MAX] = "", secondMostFrequent[MAX] = "";
    for (int i = 1; i <= n; i++) 
    {
        if (i < n && strcmp(arr[i], arr[i - 1]) == 0) 
        {
            count++;
        } else 
        {
// Update most and second most frequent
        if (count > max1) 
        {
            max2 = max1;
            strcpy(secondMostFrequent, mostFrequent);
            max1 = count;
            strcpy(mostFrequent, arr[i - 1]);
        } else if (count > max2) 
        {
            max2 = count;
            strcpy(secondMostFrequent, arr[i - 1]);
        }
        count = 1; // Reset count for next word
        }       
    }
printf("Second most repeated string: %s\n", secondMostFrequent);
}
// Driver code
int main() 
{
    char arr[][MAX] = {"apple", "banana", "apple", "orange", "banana", "banana", "grape", "apple"};
    int n = sizeof(arr) / sizeof(arr[0]);
    findSecondMostRepeated(arr, n);
    return 0;
}
//Program To return the number of nodes in the BST whose value lie in the given range.
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

=======
>>>>>>> e1e03c5e8f38efb0839739f9f6533ac95f07f169





























































































































































































































































//To return the number of nodes in the BST whose value lie in the given range.
//Optimal Approach:
//Use BST properties to avoid unnecessary traversal: 
//•	If root->data < l, search only in the right subtree.
//•	If root->data > h, search only in the left subtree.
//•	If root->data is in range [l, h], count it and explore both subtrees.
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



