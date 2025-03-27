
<-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -->

   //IN OPTIMAL APPROACH CODE:
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
 int data;
 struct Node* next;
 struct Node* prev;
} Node;
typedef struct DoublyLinkedList {
 Node* head;
 Node* tail;
} DoublyLinkedList;
Node* createNode(int data) {
 Node* newNode = (Node*)malloc(sizeof(Node));
 newNode->data = data;
 newNode->next = NULL;
 newNode->prev = NULL;
 return newNode;
}
void addNode(DoublyLinkedList* dll, int data) {
Node* newNode = createNode(data);
 if (dll->head == NULL) {
 dll->head = dll->tail = newNode;
 } else {
 dll->tail->next = newNode;
 newNode->prev = dll->tail;
 dll->tail = newNode;
 }
}
void findPairsWithSum(DoublyLinkedList* dll, int target) {
 if (dll->head == NULL || dll->tail == NULL) {
 printf("The list is empty or has only one element.\n");
 return;
 }
 Node* left = dll->head;
Node* right = dll->tail;
 printf("Pairs with sum %d:\n", target);
 int found = 0;
while (left != NULL && right != NULL && left != right && left->next != right) {
 int sum = left->data + right->data;
if (sum == target) {
printf("(%d, %d)\n", left->data, right->data);
 found = 1;
 left = left->next;
 right = right->prev;
 } else if (sum < target) {
 left = left->next;
 } else {
 right = right->prev;
 }
 }
 if (!found) {
 printf("No pairs found.\n");
 }
}
int main() {
 DoublyLinkedList dll;
 dll.head = NULL;
 dll.tail = NULL;




addNode(&dll, 1);
 addNode(&dll, 2);
 addNode(&dll, 4);
 addNode(&dll, 5);
 addNode(&dll, 6);
 addNode(&dll, 8);
 addNode(&dll, 9);
int target = 10;

findPairsWithSum(&dll, target);
 Node* temp;
 while (dll.head != NULL) {
 temp = dll.head;
 dll.head = dll.head->next;
 free(temp);
 }
 return 0;
}





//INORDER 
//OPTIMAL CODE:
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
 int val;
 struct TreeNode* left;
 struct TreeNode* right;
} TreeNode;
TreeNode* createNode(int value) {
 TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
 newNode->val = value;
 newNode->left = newNode->right = NULL;
return newNode;
}
void inorder(TreeNode* root) {
 if (root == NULL) return;
inorder(root->left);
 printf("%d ", root->val);
inorder(root->right);
}
int main() {
 TreeNode* root = createNode(3);
 root->left = createNode(2);
 root->right = createNode(4);
 root->left->left = createNode(1);
 root->left->right = createNode(5);
 root->right->left = createNode(6);
 root->right->right = createNode(8);
 inorder(root); // Output: 1 2 5 3 6 4 8
 return 0;
}

<--------------------------------------------------------------------------->

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


//Sort A Stack using recursion  

//Code for optimal approach

#include <stdio.h> 
#include <stdlib.h> 
// Structure of a stack 
typedef struct Stack { 
int top; 
int capacity; 
int *array; 
} Stack; 
// Function to create a stack 
Stack* createStack(int capacity) { 
Stack* stack = (Stack*)malloc(sizeof(Stack)); 
stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 
 
// Check if the stack is empty 
int isEmpty(Stack* stack) { 
    return stack->top == -1; 
} 
 
// Push operation 
void push(Stack* stack, int item) { 
    stack->array[++stack->top] = item; 
} 
 
// Pop operation 
int pop(Stack* stack) { 
    if (isEmpty(stack)) 
        return -1; 
    return stack->array[stack->top--]; 
} 
 
// Peek operation 
int peek(Stack* stack) { 
    return stack->array[stack->top]; 
} 
 
// Function to insert an element in sorted order 
void sortedInsert(Stack* stack, int element) { 
    if (isEmpty(stack) || peek(stack) <= element) { 
        push(stack, element); 
        return; 
    } 
     
    // Remove the top item and recursively insert the current element 
    int temp = pop(stack); 
    sortedInsert(stack, element); 
     
    // Push the popped element back 
    push(stack, temp); 
} 
 
// Function to sort the stack 
void sortStack(Stack* stack) { 
    if (!isEmpty(stack)) { 
        // Pop the top element 
        int temp = pop(stack); 
         
        // Sort the remaining stack 
        sortStack(stack); 
         
        // Insert the popped element in sorted order 
        sortedInsert(stack, temp); 
    } 
} 
 
// Function to print the stack 
void printStack(Stack* stack) { 
    while (!isEmpty(stack)) { 
        printf("%d ", pop(stack)); 
    } 
    printf("\n"); 
} 
 
// Driver code 
int main() { 
    Stack* stack = createStack(100); 
     
    push(stack, 11); 
    push(stack, 2); 
    push(stack, 32); 
    push(stack, 3); 
    push(stack, 41); 
     
    sortStack(stack); 
     
    printStack(stack); // Expected Output: 41 32 11 3 2 
     
    // Free allocated memory 
    free(stack->array); 
    free(stack); 
     
    return 0; 
}

//end of program


//Find pivot element in a sorted array

//Code for optimal approach

#include <stdio.h> 
 
// Optimal approach: Binary Search (O(log n)) 
int findPivotBinary(int arr[], int n) { 
    int low = 0, high = n - 1; 
 
    while (low <= high) { 
        int mid = low + (high - low) / 2; 
 
        // Check if mid is the pivot 
        if (mid < high && arr[mid] > arr[mid + 1]) 
            return mid; 
 
        // Check if mid-1 is the pivot 
        if (mid > low && arr[mid] < arr[mid - 1]) 
            return mid - 1; 
 
        // Move left or right 
        if (arr[low] >= arr[mid]) 
            high = mid - 1; 
        else 
            low = mid + 1; 
    } 
    return n - 1; // If no rotation found, return last index 
} 
 
// Driver Code 
int main() { 
    int arr[] = {7, 9, 11, 12, 15, 2, 5}; // Example rotated array 
    int n = sizeof(arr) / sizeof(arr[0]); 
 
    int pivotIndex = findPivotBinary(arr, n); 
    printf("Pivot element is at index %d, value %d\n", pivotIndex, arr[pivotIndex]); 
 
    return 0; 
}

//End of program
