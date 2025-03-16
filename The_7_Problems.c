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
