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


// Sort A Stack using recursion 

// Code for Recursive sorting using Insert Function:Given A stack, the task is to start to sort it such that the top of the stack has the greatest element
 
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

// End of problem